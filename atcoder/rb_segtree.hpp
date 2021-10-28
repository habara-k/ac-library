#ifndef ATCODER_RB_SEGTREE_HPP
#define ATCODER_RB_SEGTREE_HPP 1

#include "atcoder/rbtree_base"

namespace atcoder {

template<class S, S(*op)(S,S)>
struct rb_segtree_node : public rb_tree_node_base<S, rb_segtree_node<S, op>> {
    using Base = rb_tree_node_base<S, rb_segtree_node>;
    using Base::Base;
    using ptr = typename Base::ptr;
    rb_segtree_node(ptr l_, ptr r_, int red_) : Base(l_, r_, red_) {
        Base::val = op(Base::l->val, Base::r->val);
    }
};

template<class S, S(*op)(S,S), S(*e)()>
struct rb_segtree : public rb_tree_base<S, rb_segtree_node<S,op>> {
    using Node = rb_segtree_node<S,op>;
    using Base = rb_tree_base<S, Node>;
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
