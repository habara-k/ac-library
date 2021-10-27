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

    VectorPool() = default;

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
    int sz=1, rnk=0;
    bool red=false;
    S val;
    rb_tree_node_base() = default;
    explicit rb_tree_node_base(S val_) : val(val_) {}
    rb_tree_node_base(ptr l_, ptr r_, int red_) :
            l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red), red(red_) {}
    bool isLeaf() { return l == nullptr; }
};

template<class S, class Node>
struct rb_tree_base {
    using ptr = Node*;
    ptr root;

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
        if (!a) return b;
        if (!b) return a;
        ptr c = mergeSub(a, b);
        return asRoot(c);
    }

    std::pair<ptr, ptr> split(ptr p, int k) {
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
    static const bool R = true, B = false;

    VectorPool<Node> pool;

    int sz(ptr p) { return p ? p->sz : 0; }

    ptr build(const std::vector<S>& v, int l, int r) {
        if (r - l == 1) return pool.alloc(v[l]);
        return merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));
    }

    ptr mergeSub(ptr a, ptr b) {
        assert(a != nullptr);
        assert(b != nullptr);
        if (a->rnk < b->rnk) {
            ptr l = b->l, r = b->r;
            bool red = b->red;
            pool.free(b);

            ptr c = mergeSub(a, l);
            if (red or !c->red or !c->l->red) return pool.alloc(c, r, red);
            if (r->red) return pool.alloc(asRoot(c), asRoot(r), R);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return pool.alloc(cl, pool.alloc(cr, r, R), B);
        }
        if (a->rnk > b->rnk) {
            ptr l = a->l, r = a->r;
            bool red = a->red;
            pool.free(a);

            ptr c = mergeSub(r, b);
            if (red or !c->red or !c->r->red) return pool.alloc(l, c, red);
            if (l->red) return pool.alloc(asRoot(l), asRoot(c), R);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return pool.alloc(pool.alloc(l, cl, R), cr, B);
        }
        return pool.alloc(a, b, R);
    }

    ptr asRoot(ptr p) {
        if (!p) return p;
        p->red = B;
        return p;
    }
};

}  // namespace atcoder

#endif  // ATCODER_RBTREE_BASE_HPP
