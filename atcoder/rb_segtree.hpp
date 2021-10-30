#ifndef ATCODER_RB_SEGTREE_HPP
#define ATCODER_RB_SEGTREE_HPP 1

#include "atcoder/rbtree_base"

namespace atcoder {

template<class S, S(*op)(S,S)>
struct RBSegtreeNode : public RBTreeNodeBase<S, RBSegtreeNode<S, op>> {
    using Base = RBTreeNodeBase<S, RBSegtreeNode>;
    using Base::Base;
    using ptr = typename Base::ptr;
    RBSegtreeNode(ptr l_, ptr r_, int red_) : Base(l_, r_, red_) {
        Base::val = op(Base::l->val, Base::r->val);
    }
};

template<class S, S(*op)(S,S), S(*e)()>
struct RBSegtree : public RBTreeBase<S, RBSegtreeNode<S,op>> {
    using Node = RBSegtreeNode<S,op>;
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
};

}  // namespace atcoder

#endif  // ATCODER_RBTREE_BASE_HPP
