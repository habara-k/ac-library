#ifndef ATCODER_REDBLACKLAZYSEGTREE_HPP
#define ATCODER_REDBLACKLAZYSEGTREE_HPP 1

#include <cassert>
#include <vector>
#include <iostream>

namespace atcoder {

// https://ei1333.github.io/library/other/vector-pool.cpp
template<class T>
struct VectorPool {
    std::vector<T> pool;
    std::vector<T*> stock;
    int size = 0;

    VectorPool() = default;

    explicit VectorPool(int sz) : pool(sz), stock(sz) { clear(); }

    inline T *alloc() { return stock[size++]; }

    inline void free(T *t) { stock[--size] = t; }

    void clear() {
        size = 0;
        for (int i = 0; i < (int)pool.size(); i++) stock[i] = &pool[i];
    }
};

// Inspired by
// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp
// http://blog.mitaki28.info/1447078746296/
// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp

// Node

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
};

template<class S, S(*op)(S,S), S(*e)()>
struct rb_segtree_node : public rb_tree_node_base<S, rb_segtree_node<S, op, e>> {
    using Base = rb_tree_node_base<S, rb_segtree_node<S, op, e>>;
    using Base::Base;
    rb_segtree_node(rb_segtree_node *l_, rb_segtree_node *r_, int red_) : Base(l_, r_, red_) {
        Base::val = op(Base::l->val,Base::r->val);
    }
};

template<class S, S(*op)(S,S), S(*e)(), class F, F(*id)()>
struct rb_lazy_segtree_node : public rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>> {
    using Base = rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>>;
    using Base::Base;
    F lazy = id();
    rb_lazy_segtree_node(rb_lazy_segtree_node *l_, rb_lazy_segtree_node *r_, int red_) : Base(l_, r_, red_) {
        Base::val = op(Base::l->val,Base::r->val);
    }
};

template<class S, S(*op)(S,S), S(*e)(), class F, F(*id)()>
struct rb_lazy_segtree_reversible_node : public rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e, F, id>> {
    using Base = rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e, F, id>>;
    using Base::Base;
    F lazy = id();
    bool rev = false;
    rb_lazy_segtree_reversible_node(rb_lazy_segtree_reversible_node *l_, rb_lazy_segtree_reversible_node *r_, int red_) :
        Base(l_, r_, red_) { Base::val = op(Base::l->val,Base::r->val); }
};


// Tree

template<class S, class Node, class Derived>
struct rb_tree_base {
    static const bool R = true, B = false;

    using ptr = Node*;

    VectorPool<Node> pool;
    ptr root;

    explicit rb_tree_base(int max_n) : pool(2*max_n-1) {}

    int size() { return size(root); }
    int size(ptr p) { return p ? p->sz : 0; }

    void build(const std::vector<S>& v) {
        root = build(v, 0, int(v.size()));
    }

    ptr merge(ptr a, ptr b) {
        if (!a) return b;
        if (!b) return a;
        ptr c = mergeSub(a, b);
        return asRoot(c);
    }

    std::pair<ptr, ptr> split(ptr p, int k) {
        assert(0 <= k and k <= size(p));
        if (k == 0) return { nullptr, p };
        if (k == size(p)) return { p, nullptr };
        p = Derived::before_erase(p);
        ptr l = p->l, r = p->r;
        pool.free(p);
        if (k < size(l)) {
            auto [a, b] = split(l, k);
            return { a, merge(b, asRoot(r)) };
        }
        if (k > size(l)) {
            auto [a, b] = split(r, k - size(l));
            return { merge(asRoot(l), a), b };
        }
        return { asRoot(l), asRoot(r) };
    }

    void insert(int k, S val) {
        assert(0 <= k and k <= size());
        auto [l, r] = split(root, k);
        root = merge(merge(l, alloc(val)), r);
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

private:

    template<typename... U>
    ptr alloc(U... args) {
        return &(*pool.alloc() = Node(args...));
    }

    ptr build(const std::vector<S>& v, int l, int r) {
        if (r - l == 1) return alloc(v[l]);
        return merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));
    }

    ptr mergeSub(ptr a, ptr b) {
        assert(a != nullptr);
        assert(b != nullptr);
        if (a->rnk < b->rnk) {
            b = Derived::before_erase(b);
            ptr l = b->l, r = b->r;
            bool red = b->red;
            pool.free(b);

            ptr c = mergeSub(a, l);
            if (red or !c->red or !c->l->red) return alloc(c, r, red);
            if (r->red) return alloc(asRoot(c), asRoot(r), R);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return alloc(cl, alloc(cr, r, R), B);
        }
        if (a->rnk > b->rnk) {
            a = Derived::before_erase(a);
            ptr l = a->l, r = a->r;
            bool red = a->red;
            pool.free(a);

            ptr c = mergeSub(r, b);
            if (red or !c->red or !c->r->red) return alloc(l, c, red);
            if (l->red) return alloc(asRoot(l), asRoot(c), R);
            ptr cl = c->l, cr = c->r;
            pool.free(c);
            return alloc(alloc(l, cl, R), cr, B);
        }
        return alloc(a, b, R);
    }

    ptr asRoot(ptr p) {
        if (!p) return p;
        p->red = B;
        return p;
    }
};


template<class S, S(*op)(S,S), S(*e)()>
struct rb_segtree : public rb_tree_base<S, rb_segtree_node<S,op,e>, rb_segtree<S,op,e>> {
    using Base = rb_tree_base<S, rb_segtree_node<S,op,e>, rb_segtree<S,op,e>>;
    using Base::Base, Base::split, Base::merge, Base::size, Base::root;
    using ptr = rb_segtree_node<S,op,e>*;
    static ptr before_erase(ptr p) {}
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return e();

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        S val = c->val;
        root = merge(a, merge(c, b));
        return val;
    }
};

template<class S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,e,F,id>, rb_lazy_segtree<S,op,e,F,mapping,composition,id>> {
    using Base = rb_tree_base<S, rb_lazy_segtree_node<S,op,e,F,id>, rb_lazy_segtree<S,op,e,F,mapping,composition,id>>;
    using Base::Base, Base::split, Base::merge, Base::size, Base::root;
    using ptr = rb_lazy_segtree_node<S,op,e,F,id>*;
    static ptr before_erase(ptr p) {
        assert(p != nullptr);
        if (p->lazy != id()) {
            p->l = applied(p->l, p->lazy);
            p->r = applied(p->r, p->lazy);
            p->lazy = id();
        }
        return p;
    }
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return e();

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        S val = c->val;
        root = merge(a, merge(c, b));
        return val;
    }
    void apply(int l, int r, F lazy) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return;

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        root = merge(a, merge(applied(c, lazy), b));
    }
private:
    static ptr applied(ptr p, const F& lazy) {
        assert(p != nullptr);
        p->val = mapping(lazy, p->val);
        if (p->l) p->lazy = composition(p->lazy, lazy);
        return p;
    }
};


template<class S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct rb_lazy_segtree_reversible : public rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>, rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>> {
    using Base = rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>, rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>>;
    using Base::Base, Base::split, Base::merge, Base::size, Base::root;
    using ptr = rb_lazy_segtree_reversible_node<S,op,e,F,id>*;
    static ptr before_erase(ptr p) {
        assert(p != nullptr);
        if (p->lazy != id()) {
            p->l = applied(p->l, p->lazy);
            p->r = applied(p->r, p->lazy);
            p->lazy = id();
        }
        if (p->rev) {
            p->l = reversed(p->l);
            p->r = reversed(p->r);
            p->rev = false;
        }
        return p;
    }
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return e();

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        S val = c->val;
        root = merge(a, merge(c, b));
        return val;
    }
    void apply(int l, int r, F lazy) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return;

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        root = merge(a, merge(applied(c, lazy), b));
    }
    void reverse(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return;

        auto [a, tmp] = split(root, l);
        auto [c, b] = split(tmp, r-l);
        root = merge(a, merge(reversed(c), b));
    }
private:
    static ptr applied(ptr p, const F& lazy) {
        assert(p != nullptr);
        p->val = mapping(lazy, p->val);
        if (p->l) p->lazy = composition(p->lazy, lazy);
        return p;
    }
    static ptr reversed(ptr p) {
        assert(p != nullptr);
        std::swap(p->l, p->r);
        if (p->l) p->rev ^= 1;
        return p;
    }
};

}  // namespace atcoder

#endif  // ATCODER_REDBLACKLAZYSEGTREE_HPP
