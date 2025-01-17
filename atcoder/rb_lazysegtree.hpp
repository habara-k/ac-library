#ifndef ATCODER_RB_LAZYSEGTREE_HPP
#define ATCODER_RB_LAZYSEGTREE_HPP 1

#include "atcoder/rbtree_base"

namespace atcoder {

template<class S, S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct RBLazySegtreeNode : public RBTreeNodeBase<S, RBLazySegtreeNode<S,op,F,mapping,composition,id>> {
    using Base = RBTreeNodeBase<S, RBLazySegtreeNode>;
    using Base::Base, Base::l, Base::r, Base::val, Base::isLeaf;
    F lazy = id();
    using ptr = typename Base::ptr;
    RBLazySegtreeNode(ptr l_, ptr r_, int red_) : Base(l_, r_, red_) {
        val = op(l->val, r->val);
    }
    ~RBLazySegtreeNode() {
        if (lazy != id()) {
            assert(!isLeaf());
            l = applied(l, lazy);
            r = applied(r, lazy);
        }
    }
    static ptr applied(ptr p, const F& lazy) {
        assert(p != nullptr);
        p->val = mapping(lazy, p->val);
        if (!p->isLeaf()) p->lazy = composition(p->lazy, lazy);
        return p;
    }
};

template<class S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct RBLazySegtree : public RBTreeBase<S, RBLazySegtreeNode<S,op,F,mapping,composition,id>> {
    using Node = RBLazySegtreeNode<S,op,F,mapping,composition,id>;
    using Base = RBTreeBase<S, Node>;
    using Base::Base, Base::size;
private:
    using Base::split, Base::merge, Base::root;
public:
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
        root = merge(a, merge(Node::applied(c, lazy), b));
    }
};

}  // namespace atcoder

#endif  // ATCODER_RB_LAZYSEGTREE_HPP
