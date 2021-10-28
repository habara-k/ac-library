#ifndef ATCODER_RBTREE_BASE_HPP
#define ATCODER_RBTREE_BASE_HPP 1

#include <vector>
#include <cassert>

// References:
// https://ei1333.github.io/library/other/vector-pool.cpp

namespace atcoder {

template<class T>
struct VectorPool {
    std::vector<T> pool;
    std::vector<T*> stock;
    int size = 0;

    explicit VectorPool(int sz) : pool(sz), stock(sz) { clear(); }

    template<typename... U>
    T *alloc(U... args) { return &(*stock[size++] = T(args...)); }

    inline void free(T *t) { (stock[--size] = t)->~T(); }

    void clear() {
        size = 0;
        for (int i = 0; i < (int)pool.size(); i++) stock[i] = &pool[i];
    }
};

// References:
// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp
// http://blog.mitaki28.info/1447078746296/
// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp

template<class S, class Derived>
struct rb_tree_node_base {
    using ptr = Derived*;
    ptr l=nullptr, r=nullptr;
    int size=1, rank=0;
    bool red=false;
    S val;
    rb_tree_node_base() = default;
    explicit rb_tree_node_base(S val_) : val(val_) {}
    rb_tree_node_base(ptr l_, ptr r_, int red_) :
            l(l_), r(r_), size(l->size + r->size), rank(l->rank + !l->red), red(red_) {}
    bool isLeaf() { return l == nullptr; }
};

template<class S, class Node>
struct rb_tree_base {
    using ptr = typename Node::ptr;
    ptr root;
    // Ensure: root is null or valid

    // valid <=>
    // - The root and leaves are black
    // - Red nodes are not adjacent
    // - The number of black nodes on the root-to-leaf path is constant

    explicit rb_tree_base(int max_n) : pool(2*max_n-1) {}

    int size() { return sz(root); }

    void build(const std::vector<S>& v) {
        root = build(v, 0, int(v.size()));
    }

    void insert(int k, S val) {
        assert(0 <= k and k <= size());
        auto [l, r] = split(root, k);
        root = merge(merge(l, pool.alloc(val)), r);
    }

    S erase(int k) {
        assert(0 <= k and k < size());
        auto [l, tmp] = split(root, k);
        auto [c, r] = split(tmp, 1);
        S val = c->val;
        pool.free(c);
        root = merge(l, r);
        return val;
    }

    S get(int k) {
        assert(0 <= k and k < size());
        auto [a, tmp] = split(root, k);
        auto [c, b] = split(tmp, 1);
        S val = c->val;
        root = merge(a, merge(c, b));
        return val;
    }

    ptr merge(ptr a, ptr b) {
        // Require:
        // - a, b: null or valid
        if (!a) return b;
        if (!b) return a;
        return asRoot(mergeSub(a, b));
    }

    std::pair<ptr, ptr> split(ptr p, int k) {
        // Require:
        // - p: null or asRoot(p) is valid
        // Ensure:
        // - returned nodes are null or valid
        assert(0 <= k and k <= sz(p));
        if (k == 0) return { nullptr, p };
        if (k == sz(p)) return { p, nullptr };
        ptr l = p->l, r = p->r;
        pool.free(p);
        if (k < sz(l)) {
            auto [a, b] = split(l, k);
            return { a, merge(b, asRoot(r)) };
        }
        if (k > sz(l)) {
            auto [a, b] = split(r, k - sz(l));
            return { merge(asRoot(l), a), b };
        }
        return { asRoot(l), asRoot(r) };
    }

private:
    static const bool RED = true, BLACK = false;

    VectorPool<Node> pool;

    int sz(ptr p) { return p ? p->size : 0; }

    ptr build(const std::vector<S>& v, int l, int r) {
        if (r - l == 1) return pool.alloc(v[l]);
        return merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));
    }

    ptr mergeSub(ptr a, ptr b) {
        // Require:
        // - asRoot(a), asRoot(b) is valid
        // Ensure:
        // - asRoot(returned node) is valid
        // - (returned node)->rank = max(a->rank, b->rank)
        assert(a != nullptr);
        assert(b != nullptr);
        if (a->rank < b->rank or (a->rank == b->rank and b->red)) {
            ptr l = b->l, r = b->r;
            bool red = b->red;
            pool.free(b);
            ptr c = mergeSub(a, l);
            if (red or !c->red or !c->l->red) return pool.alloc(c, r, red);
            if (r->red) return pool.alloc(asRoot(c), asRoot(r), RED);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return pool.alloc(cl, pool.alloc(cr, r, RED), BLACK);
        }
        if (a->rank > b->rank or (a->rank == b->rank and a->red)) {
            ptr l = a->l, r = a->r;
            bool red = a->red;
            pool.free(a);
            ptr c = mergeSub(r, b);
            if (red or !c->red or !c->r->red) return pool.alloc(l, c, red);
            if (l->red) return pool.alloc(asRoot(l), asRoot(c), RED);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return pool.alloc(pool.alloc(l, cl, RED), cr, BLACK);
        }
        return pool.alloc(a, b, RED);
    }

    ptr asRoot(ptr p) {
        if (!p) return p;
        p->red = BLACK;
        return p;
    }
};

}  // namespace atcoder

#endif  // ATCODER_RBTREE_BASE_HPP
