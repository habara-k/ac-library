#ifndef ATCODER_REDBLACKLAZYSEGTREE_HPP
#define ATCODER_REDBLACKLAZYSEGTREE_HPP 1

#include <vector>

namespace atcoder {

using namespace std;

template<
        class S,
        S (*op)(S,S),
        S (*e)(),
        class F,
        S (*mapping)(S, F),
        F (*composition)(F, F),
        F (*id)(),
        int POOL>
struct RedBlackLazySegmentTree {
    RedBlackLazySegmentTree() : pool(POOL), stock(POOL) { clear(); }

    static const bool R = false, B = true;
    struct node {
        node *l=nullptr, *r=nullptr;
        S prd = e();
        F lazy = id();
        int sz=1, rnk=0;
        bool color=B;
        node() = default;
        explicit node(S val) : prd(val) {}
        node(node *l_, node *r_, int color_) : l(l_), r(r_), prd(op(l->prd,r->prd)),
                                            sz(l->sz + r->sz), rnk(l->rnk + l->color), color(color_) {}
    };
    int size() { return size(root); }
    int size(node *p) { return p ? p->sz : 0; }

    void build(const vector<S>& v) {
        root = build(v, 0, int(v.size()));
    }

    node* merge(node *a, node *b) {
        if (!a) return b;
        if (!b) return a;
        auto c = merge_sub(a, b);
        return as_root(c);
    }
    pair<node*, node*> split(node *a, int k) {
        assert(0 <= k and k <= size(a));
        if (k == 0) return {nullptr, a};
        if (k == size(a)) return {a, nullptr};
        a = push(a);
        node *l = a->l, *r = a->r;
        del(a);
        if (k < l->sz) {
            auto p = split(l, k);
            return {p.first, merge(p.second, as_root(r))};
        }
        if (k > l->sz) {
            auto p = split(r, k - l->sz);
            return {merge(as_root(l), p.first), p.second};
        }
        return {as_root(l), as_root(r)};
    }

    void insert(int k, S val) {
        assert(0 <= k and k <= size());
        auto p = split(root, k);
        root = merge(merge(p.first, alloc(val)), p.second);
    }
    S erase(int k) {
        assert(0 <= k and k < size());
        auto p = split(root, k);
        auto q = split(p.second, 1);
        S val = q.first->prd;
        del(q.first);
        root = merge(p.first, q.second);
        return val;
    }

    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        return prod(root, 0, root->sz, id(), l, r);
    }
    S operator[](int k) {
        assert(0 <= k and k < size());
        return prod(k, k+1);
    }
    void apply(int l, int r, F lazy) {
        assert(0 <= l and l <= r and r <= size());
        auto p = split(root, l);
        auto q = split(p.second, r-l);
        root = merge(p.first, merge(set_lazy(q.first, lazy), q.second));
    }
    node* root;

protected:

    vector<node> pool;
    vector<node*> stock;
    int head = POOL;

    template<typename... U>
    node* alloc(U... args) {
        return &(*stock[--head] = node(args...));
    }
    void del(node* p) {
        stock[head++] = p;
    }
    void clear() {
        head = POOL;
        for (int i = 0; i < POOL; ++i) stock[i] = &pool[i];
    }

    node* set_lazy(node* p, const F& lazy) {
        p->prd = mapping(p->prd, lazy);
        if (p->l) p->lazy = composition(p->lazy, lazy);
        return p;
    }

    node* push(node *p) {
        if (p->lazy == id()) return p;
        p->l = set_lazy(p->l, p->lazy);
        p->r = set_lazy(p->r, p->lazy);
        p->lazy = id();
        return p;
    }

    node* build(const vector<S>& v, int l, int r) {
        if (r - l == 1) return alloc(v[l]);
        return merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));
    }

    node* merge_sub(node *a, node *b) {
        if (a->rnk < b->rnk) {
            b = push(b);
            auto c = merge_sub(a, b->l);
            node *ret;
            if (b->color and !c->color and !c->l->color) {
                if (b->r->color) ret = alloc(c->l, alloc(c->r, b->r, R), B), del(c);
                else ret = alloc(as_root(c), as_root(b->r), R);
            } else {
                ret = alloc(c, b->r, b->color);
            }
            del(b); return ret;
        } else if (a->rnk > b->rnk) {
            a = push(a);
            auto c = merge_sub(a->r, b);
            node *ret;
            if (a->color and !c->color and !c->r->color) {
                if (a->l->color) ret = alloc(alloc(a->l, c->l, R), c->r, B), del(c);
                else ret = alloc(as_root(a->l), as_root(c), R);
            } else {
                ret = alloc(a->l, c, a->color);
            }
            del(a); return ret;
        } else {
            return alloc(a, b, R);
        }
    }

    node* as_root(node *p) {
        if (!p or p->color) return p;
        p->color = B;
        return p;
    }

    S prod(node *p, int a, int b, F lazy, int l, int r) {
        if (b <= l or r <= a) return e();
        if (l <= a and b <= r) return mapping(p->prd, lazy);
        return op(prod(p->l, a, a + p->l->sz, composition(p->lazy, lazy), l, r),
                  prod(p->r, b - p->r->sz, b, composition(p->lazy, lazy), l, r));
    }
};

}  // namespace atcoder

#endif  // ATCODER_REDBLACKLAZYSEGTREE_HPP
