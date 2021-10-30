#ifndef ATCODER_RB_LAZYSEGTREE_REVERSIBLE_HPP
#define ATCODER_RB_LAZYSEGTREE_REVERSIBLE_HPP 1

#include "atcoder/rbtree_base"

namespace atcoder {

template<class S, S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct RBLazySegtreeReversibleNode : public RBTreeNodeBase<S, RBLazySegtreeReversibleNode<S,op,F,mapping,composition,id>> {
    using Base = RBTreeNodeBase<S, RBLazySegtreeReversibleNode>;
    using Base::Base, Base::l, Base::r, Base::val, Base::isLeaf;
    F lazy = id();
    bool rev = false;
    using ptr = typename Base::ptr;
    RBLazySegtreeReversibleNode(ptr l_, ptr r_, int red_) :
            Base(l_, r_, red_) { val = op(l->val, r->val); }
    ~RBLazySegtreeReversibleNode() {
        if (lazy != id()) {
            assert(!isLeaf());
            l = applied(l, lazy);
            r = applied(r, lazy);
        }
        if (rev) {
            assert(!isLeaf());
            l = reversed(l);
            r = reversed(r);
        }
    }
    static ptr applied(ptr p, const F& lazy) {
        assert(p != nullptr);
        p->val = mapping(lazy, p->val);
        if (!p->isLeaf()) p->lazy = composition(p->lazy, lazy);
        return p;
    }
    static ptr reversed(ptr p) {
        assert(p != nullptr);
        std::swap(p->l, p->r);
        if (!p->isLeaf()) p->rev ^= 1;
        return p;
    }
};

template<class S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>
struct RBLazySegtreeReversible : public RBTreeBase<S, RBLazySegtreeReversibleNode<S,op,F,mapping,composition,id>> {
    using Node = RBLazySegtreeReversibleNode<S,op,F,mapping,composition,id>;
    using Base = RBTreeBase<S, Node>;
    using Base::Base, Base::size;
private:
    using Base::split, Base::merge, Base::root;
public:
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return e();

        auto [tmp, c] = split(root, r);
        auto [a, b] = split(tmp, l);
        S val = b->val;
        root = merge(merge(a, b), c);
        return val;
    }
    void apply(int l, int r, F lazy) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return;

        auto [tmp, c] = split(root, r);
        auto [a, b] = split(tmp, l);
        root = merge(merge(a, Node::applied(b, lazy)), c);
    }
    void reverse(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if (l == r) return;

        auto [tmp, c] = split(root, r);
        auto [a, b] = split(tmp, l);
        root = merge(merge(a, Node::reversed(b)), c);
    }
};

}  // namespace atcoder

#endif  // ATCODER_RB_LAZYSEGTREE_REVERSIBLE_HPP
