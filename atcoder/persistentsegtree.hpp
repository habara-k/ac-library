#ifndef ATCODER_PERSISTENTSEGTREE_HPP
#define ATCODER_PERSISTENTSEGTREE 1

#include <cassert>
#include <vector>

namespace atcoder {

template<class S, S (*op)(S, S), S (*e)()>
struct PersistentSegmentTree {
    struct Node;
    using ptr = Node*;
    struct Node {
        ptr l=nullptr, r=nullptr;
        S x;
        explicit Node(S x_) : x(x_) {}
        Node(ptr l_, ptr r_) : l(l_), r(r_), x(op(l->x, r->x)) {}
    };

    int n = 0;

    ptr build(int n_) {
        return build(std::vector<S>(n_, e()));
    }
    ptr build(const std::vector<S>& v) {
        n = (int)v.size();
        return build(0, n, v);
    }

    ptr set(ptr root, int k, const S& x) {
        assert(0 <= k and k < n);
        return set(root, k, x, 0, n);
    }

    S prod(ptr root, int a, int b) {
        assert(0 <= a and a <= b and b <= n);
        return prod(root, a, b, 0, n);
    }

    S get(ptr root, int k) {
        assert(0 <= k and k < n);
        return prod(root, k, k + 1);
    }

private:
    ptr build(int l, int r, const std::vector<S>& v) const {
        assert(l < r);
        if (l+1 == r) return new Node(v[l]);
        return new Node(build(l, (l+r)>>1, v), build((l+r)>>1, r, v));
    }
    ptr set(ptr t, int k, const S& x, int l, int r) const {
        assert(l < r);
        if (k == l and k+1 == r) return new Node(x);
        if (r <= k or k < l) return t;
        return new Node(set(t->l, k, x, l, (l+r)>>1),
                        set(t->r, k, x, (l+r)>>1, r));
    }

    S prod(ptr t, int a, int b, int l, int r) const {
        assert(l < r);
        if (r <= a or b <= l) return e();
        if (a <= l and r <= b) return t->x;
        return op(prod(t->l, a, b, l, (l+r)>>1),
                  prod(t->r, a, b, (l+r)>>1, r));
    }
};

}  // namespace atcoder

#endif  // ATCODER_PERSISTENTSEGTREE_HPP
