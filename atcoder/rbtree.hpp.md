---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/redblacklazysegtree.test.cpp
    title: test/redblacklazysegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://blog.mitaki28.info/1447078746296/
    - https://ei1333.github.io/library/other/vector-pool.cpp
    - https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp
    - https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
    - https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp
  bundledCode: "#line 1 \"atcoder/rbtree.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n#include <iostream>\n\nnamespace atcoder {\n\n// https://ei1333.github.io/library/other/vector-pool.cpp\n\
    template<class T>\nstruct VectorPool {\n    std::vector<T> pool;\n    std::vector<T*>\
    \ stock;\n    int size = 0;\n\n    VectorPool() = default;\n\n    explicit VectorPool(int\
    \ sz) : pool(sz), stock(sz) { clear(); }\n\n    inline T *alloc() { return stock[size++];\
    \ }\n\n    inline void free(T *t) { stock[--size] = t; }\n\n    void clear() {\n\
    \        size = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i]\
    \ = &pool[i];\n    }\n};\n\n// Inspired by\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \n// Node\n\ntemplate<class S, class Derived>\nstruct rb_tree_node_base {\n  \
    \  using ptr = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int sz=1, rnk=0;\n\
    \    bool red=false;\n    S val;\n    rb_tree_node_base() = default;\n    explicit\
    \ rb_tree_node_base(S val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr\
    \ r_, int red_) :\n        l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red),\
    \ red(red_) {}\n};\n\ntemplate<class S, S(*op)(S,S), S(*e)()>\nstruct rb_segtree_node\
    \ : public rb_tree_node_base<S, rb_segtree_node<S, op, e>> {\n    using Base =\
    \ rb_tree_node_base<S, rb_segtree_node<S, op, e>>;\n    using Base::Base;\n  \
    \  rb_segtree_node(rb_segtree_node *l_, rb_segtree_node *r_, int red_) : Base(l_,\
    \ r_, red_) {\n        Base::val = op(Base::l->val,Base::r->val);\n    }\n};\n\
    \ntemplate<class S, S(*op)(S,S), S(*e)(), class F, F(*id)()>\nstruct rb_lazy_segtree_node\
    \ : public rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>> {\n   \
    \ using Base = rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>>;\n\
    \    using Base::Base;\n    F lazy = id();\n    rb_lazy_segtree_node(rb_lazy_segtree_node\
    \ *l_, rb_lazy_segtree_node *r_, int red_) : Base(l_, r_, red_) {\n        Base::val\
    \ = op(Base::l->val,Base::r->val);\n    }\n};\n\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, F(*id)()>\nstruct rb_lazy_segtree_reversible_node : public\
    \ rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e, F, id>> {\n \
    \   using Base = rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e,\
    \ F, id>>;\n    using Base::Base;\n    F lazy = id();\n    bool rev = false;\n\
    \    rb_lazy_segtree_reversible_node(rb_lazy_segtree_reversible_node *l_, rb_lazy_segtree_reversible_node\
    \ *r_, int red_) :\n        Base(l_, r_, red_) { Base::val = op(Base::l->val,Base::r->val);\
    \ }\n};\n\n\n// Tree\n\ntemplate<class S, class Node, class Derived>\nstruct rb_tree_base\
    \ {\n    static const bool R = true, B = false;\n\n    using ptr = Node*;\n\n\
    \    VectorPool<Node> pool;\n    ptr root;\n\n    explicit rb_tree_base(int max_n)\
    \ : pool(2*max_n-1) {}\n\n    int size() { return size(root); }\n    int size(ptr\
    \ p) { return p ? p->sz : 0; }\n\n    void build(const std::vector<S>& v) {\n\
    \        root = build(v, 0, int(v.size()));\n    }\n\n    ptr merge(ptr a, ptr\
    \ b) {\n        if (!a) return b;\n        if (!b) return a;\n        ptr c =\
    \ mergeSub(a, b);\n        return asRoot(c);\n    }\n\n    std::pair<ptr, ptr>\
    \ split(ptr p, int k) {\n        assert(0 <= k and k <= size(p));\n        if\
    \ (k == 0) return { nullptr, p };\n        if (k == size(p)) return { p, nullptr\
    \ };\n        p = Derived::before_erase(p);\n        ptr l = p->l, r = p->r;\n\
    \        pool.free(p);\n        if (k < size(l)) {\n            auto [a, b] =\
    \ split(l, k);\n            return { a, merge(b, asRoot(r)) };\n        }\n  \
    \      if (k > size(l)) {\n            auto [a, b] = split(r, k - size(l));\n\
    \            return { merge(asRoot(l), a), b };\n        }\n        return { asRoot(l),\
    \ asRoot(r) };\n    }\n\n    void insert(int k, S val) {\n        assert(0 <=\
    \ k and k <= size());\n        auto [l, r] = split(root, k);\n        root = merge(merge(l,\
    \ alloc(val)), r);\n    }\n    S erase(int k) {\n        assert(0 <= k and k <\
    \ size());\n        auto [l, tmp] = split(root, k);\n        auto [c, r] = split(tmp,\
    \ 1);\n        S val = c->val;\n        pool.free(c);\n        root = merge(l,\
    \ r);\n        return val;\n    }\n    S get(int k) {\n        assert(0 <= k and\
    \ k < size());\n        auto [a, tmp] = split(root, k);\n        auto [c, b] =\
    \ split(tmp, 1);\n        S val = c->val;\n        root = merge(a, merge(c, b));\n\
    \        return val;\n    }\n\nprivate:\n\n    template<typename... U>\n    ptr\
    \ alloc(U... args) {\n        return &(*pool.alloc() = Node(args...));\n    }\n\
    \n    ptr build(const std::vector<S>& v, int l, int r) {\n        if (r - l ==\
    \ 1) return alloc(v[l]);\n        return merge(build(v, l, (l+r)/2), build(v,\
    \ (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n        assert(a !=\
    \ nullptr);\n        assert(b != nullptr);\n        if (a->rnk < b->rnk) {\n \
    \           b = Derived::before_erase(b);\n            ptr l = b->l, r = b->r;\n\
    \            bool red = b->red;\n            pool.free(b);\n\n            ptr\
    \ c = mergeSub(a, l);\n            if (red or !c->red or !c->l->red) return alloc(c,\
    \ r, red);\n            if (r->red) return alloc(asRoot(c), asRoot(r), R);\n \
    \           ptr cl = c->l, cr = c->r;\n            pool.free(c);\n           \
    \ return alloc(cl, alloc(cr, r, R), B);\n        }\n        if (a->rnk > b->rnk)\
    \ {\n            a = Derived::before_erase(a);\n            ptr l = a->l, r =\
    \ a->r;\n            bool red = a->red;\n            pool.free(a);\n\n       \
    \     ptr c = mergeSub(r, b);\n            if (red or !c->red or !c->r->red) return\
    \ alloc(l, c, red);\n            if (l->red) return alloc(asRoot(l), asRoot(c),\
    \ R);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n    \
    \        return alloc(alloc(l, cl, R), cr, B);\n        }\n        return alloc(a,\
    \ b, R);\n    }\n\n    ptr asRoot(ptr p) {\n        if (!p) return p;\n      \
    \  p->red = B;\n        return p;\n    }\n};\n\n\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)()>\nstruct rb_segtree : public rb_tree_base<S, rb_segtree_node<S,op,e>,\
    \ rb_segtree<S,op,e>> {\n    using Base = rb_tree_base<S, rb_segtree_node<S,op,e>,\
    \ rb_segtree<S,op,e>>;\n    using Base::Base, Base::split, Base::merge, Base::size,\
    \ Base::root;\n    using ptr = rb_segtree_node<S,op,e>*;\n    static ptr before_erase(ptr\
    \ p) {}\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ size());\n        if (l == r) return e();\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        S val = c->val;\n     \
    \   root = merge(a, merge(c, b));\n        return val;\n    }\n};\n\ntemplate<class\
    \ S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\n\
    struct rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,e,F,id>,\
    \ rb_lazy_segtree<S,op,e,F,mapping,composition,id>> {\n    using Base = rb_tree_base<S,\
    \ rb_lazy_segtree_node<S,op,e,F,id>, rb_lazy_segtree<S,op,e,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::split, Base::merge, Base::size, Base::root;\n   \
    \ using ptr = rb_lazy_segtree_node<S,op,e,F,id>*;\n    static ptr before_erase(ptr\
    \ p) {\n        assert(p != nullptr);\n        if (p->lazy != id()) {\n      \
    \      p->l = applied(p->l, p->lazy);\n            p->r = applied(p->r, p->lazy);\n\
    \            p->lazy = id();\n        }\n        return p;\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n        if\
    \ (l == r) return e();\n\n        auto [a, tmp] = split(root, l);\n        auto\
    \ [c, b] = split(tmp, r-l);\n        S val = c->val;\n        root = merge(a,\
    \ merge(c, b));\n        return val;\n    }\n    void apply(int l, int r, F lazy)\
    \ {\n        assert(0 <= l and l <= r and r <= size());\n        if (l == r) return;\n\
    \n        auto [a, tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n\
    \        root = merge(a, merge(applied(c, lazy), b));\n    }\nprivate:\n    static\
    \ ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n       \
    \ p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n};\n\n\ntemplate<class S, S(*op)(S,S), S(*e)(),\
    \ class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct rb_lazy_segtree_reversible\
    \ : public rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>, rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>,\
    \ rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>>;\n    using Base::Base,\
    \ Base::split, Base::merge, Base::size, Base::root;\n    using ptr = rb_lazy_segtree_reversible_node<S,op,e,F,id>*;\n\
    \    static ptr before_erase(ptr p) {\n        assert(p != nullptr);\n       \
    \ if (p->lazy != id()) {\n            p->l = applied(p->l, p->lazy);\n       \
    \     p->r = applied(p->r, p->lazy);\n            p->lazy = id();\n        }\n\
    \        if (p->rev) {\n            p->l = reversed(p->l);\n            p->r =\
    \ reversed(p->r);\n            p->rev = false;\n        }\n        return p;\n\
    \    }\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ size());\n        if (l == r) return e();\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        S val = c->val;\n     \
    \   root = merge(a, merge(c, b));\n        return val;\n    }\n    void apply(int\
    \ l, int r, F lazy) {\n        assert(0 <= l and l <= r and r <= size());\n  \
    \      if (l == r) return;\n\n        auto [a, tmp] = split(root, l);\n      \
    \  auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(applied(c, lazy),\
    \ b));\n    }\n    void reverse(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] =\
    \ split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a,\
    \ merge(reversed(c), b));\n    }\nprivate:\n    static ptr applied(ptr p, const\
    \ F& lazy) {\n        assert(p != nullptr);\n        p->val = mapping(lazy, p->val);\n\
    \        if (p->l) p->lazy = composition(p->lazy, lazy);\n        return p;\n\
    \    }\n    static ptr reversed(ptr p) {\n        assert(p != nullptr);\n    \
    \    std::swap(p->l, p->r);\n        if (p->l) p->rev ^= 1;\n        return p;\n\
    \    }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_RBTREE_HPP\n#define ATCODER_RBTREE_HPP 1\n\n#include <cassert>\n\
    #include <vector>\n#include <iostream>\n\nnamespace atcoder {\n\n// https://ei1333.github.io/library/other/vector-pool.cpp\n\
    template<class T>\nstruct VectorPool {\n    std::vector<T> pool;\n    std::vector<T*>\
    \ stock;\n    int size = 0;\n\n    VectorPool() = default;\n\n    explicit VectorPool(int\
    \ sz) : pool(sz), stock(sz) { clear(); }\n\n    inline T *alloc() { return stock[size++];\
    \ }\n\n    inline void free(T *t) { stock[--size] = t; }\n\n    void clear() {\n\
    \        size = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i]\
    \ = &pool[i];\n    }\n};\n\n// Inspired by\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \n// Node\n\ntemplate<class S, class Derived>\nstruct rb_tree_node_base {\n  \
    \  using ptr = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int sz=1, rnk=0;\n\
    \    bool red=false;\n    S val;\n    rb_tree_node_base() = default;\n    explicit\
    \ rb_tree_node_base(S val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr\
    \ r_, int red_) :\n        l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red),\
    \ red(red_) {}\n};\n\ntemplate<class S, S(*op)(S,S), S(*e)()>\nstruct rb_segtree_node\
    \ : public rb_tree_node_base<S, rb_segtree_node<S, op, e>> {\n    using Base =\
    \ rb_tree_node_base<S, rb_segtree_node<S, op, e>>;\n    using Base::Base;\n  \
    \  rb_segtree_node(rb_segtree_node *l_, rb_segtree_node *r_, int red_) : Base(l_,\
    \ r_, red_) {\n        Base::val = op(Base::l->val,Base::r->val);\n    }\n};\n\
    \ntemplate<class S, S(*op)(S,S), S(*e)(), class F, F(*id)()>\nstruct rb_lazy_segtree_node\
    \ : public rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>> {\n   \
    \ using Base = rb_tree_node_base<S, rb_lazy_segtree_node<S, op, e, F, id>>;\n\
    \    using Base::Base;\n    F lazy = id();\n    rb_lazy_segtree_node(rb_lazy_segtree_node\
    \ *l_, rb_lazy_segtree_node *r_, int red_) : Base(l_, r_, red_) {\n        Base::val\
    \ = op(Base::l->val,Base::r->val);\n    }\n};\n\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, F(*id)()>\nstruct rb_lazy_segtree_reversible_node : public\
    \ rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e, F, id>> {\n \
    \   using Base = rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S, op, e,\
    \ F, id>>;\n    using Base::Base;\n    F lazy = id();\n    bool rev = false;\n\
    \    rb_lazy_segtree_reversible_node(rb_lazy_segtree_reversible_node *l_, rb_lazy_segtree_reversible_node\
    \ *r_, int red_) :\n        Base(l_, r_, red_) { Base::val = op(Base::l->val,Base::r->val);\
    \ }\n};\n\n\n// Tree\n\ntemplate<class S, class Node, class Derived>\nstruct rb_tree_base\
    \ {\n    static const bool R = true, B = false;\n\n    using ptr = Node*;\n\n\
    \    VectorPool<Node> pool;\n    ptr root;\n\n    explicit rb_tree_base(int max_n)\
    \ : pool(2*max_n-1) {}\n\n    int size() { return size(root); }\n    int size(ptr\
    \ p) { return p ? p->sz : 0; }\n\n    void build(const std::vector<S>& v) {\n\
    \        root = build(v, 0, int(v.size()));\n    }\n\n    ptr merge(ptr a, ptr\
    \ b) {\n        if (!a) return b;\n        if (!b) return a;\n        ptr c =\
    \ mergeSub(a, b);\n        return asRoot(c);\n    }\n\n    std::pair<ptr, ptr>\
    \ split(ptr p, int k) {\n        assert(0 <= k and k <= size(p));\n        if\
    \ (k == 0) return { nullptr, p };\n        if (k == size(p)) return { p, nullptr\
    \ };\n        p = Derived::before_erase(p);\n        ptr l = p->l, r = p->r;\n\
    \        pool.free(p);\n        if (k < size(l)) {\n            auto [a, b] =\
    \ split(l, k);\n            return { a, merge(b, asRoot(r)) };\n        }\n  \
    \      if (k > size(l)) {\n            auto [a, b] = split(r, k - size(l));\n\
    \            return { merge(asRoot(l), a), b };\n        }\n        return { asRoot(l),\
    \ asRoot(r) };\n    }\n\n    void insert(int k, S val) {\n        assert(0 <=\
    \ k and k <= size());\n        auto [l, r] = split(root, k);\n        root = merge(merge(l,\
    \ alloc(val)), r);\n    }\n    S erase(int k) {\n        assert(0 <= k and k <\
    \ size());\n        auto [l, tmp] = split(root, k);\n        auto [c, r] = split(tmp,\
    \ 1);\n        S val = c->val;\n        pool.free(c);\n        root = merge(l,\
    \ r);\n        return val;\n    }\n    S get(int k) {\n        assert(0 <= k and\
    \ k < size());\n        auto [a, tmp] = split(root, k);\n        auto [c, b] =\
    \ split(tmp, 1);\n        S val = c->val;\n        root = merge(a, merge(c, b));\n\
    \        return val;\n    }\n\nprivate:\n\n    template<typename... U>\n    ptr\
    \ alloc(U... args) {\n        return &(*pool.alloc() = Node(args...));\n    }\n\
    \n    ptr build(const std::vector<S>& v, int l, int r) {\n        if (r - l ==\
    \ 1) return alloc(v[l]);\n        return merge(build(v, l, (l+r)/2), build(v,\
    \ (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n        assert(a !=\
    \ nullptr);\n        assert(b != nullptr);\n        if (a->rnk < b->rnk) {\n \
    \           b = Derived::before_erase(b);\n            ptr l = b->l, r = b->r;\n\
    \            bool red = b->red;\n            pool.free(b);\n\n            ptr\
    \ c = mergeSub(a, l);\n            if (red or !c->red or !c->l->red) return alloc(c,\
    \ r, red);\n            if (r->red) return alloc(asRoot(c), asRoot(r), R);\n \
    \           ptr cl = c->l, cr = c->r;\n            pool.free(c);\n           \
    \ return alloc(cl, alloc(cr, r, R), B);\n        }\n        if (a->rnk > b->rnk)\
    \ {\n            a = Derived::before_erase(a);\n            ptr l = a->l, r =\
    \ a->r;\n            bool red = a->red;\n            pool.free(a);\n\n       \
    \     ptr c = mergeSub(r, b);\n            if (red or !c->red or !c->r->red) return\
    \ alloc(l, c, red);\n            if (l->red) return alloc(asRoot(l), asRoot(c),\
    \ R);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n    \
    \        return alloc(alloc(l, cl, R), cr, B);\n        }\n        return alloc(a,\
    \ b, R);\n    }\n\n    ptr asRoot(ptr p) {\n        if (!p) return p;\n      \
    \  p->red = B;\n        return p;\n    }\n};\n\n\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)()>\nstruct rb_segtree : public rb_tree_base<S, rb_segtree_node<S,op,e>,\
    \ rb_segtree<S,op,e>> {\n    using Base = rb_tree_base<S, rb_segtree_node<S,op,e>,\
    \ rb_segtree<S,op,e>>;\n    using Base::Base, Base::split, Base::merge, Base::size,\
    \ Base::root;\n    using ptr = rb_segtree_node<S,op,e>*;\n    static ptr before_erase(ptr\
    \ p) {}\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ size());\n        if (l == r) return e();\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        S val = c->val;\n     \
    \   root = merge(a, merge(c, b));\n        return val;\n    }\n};\n\ntemplate<class\
    \ S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\n\
    struct rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,e,F,id>,\
    \ rb_lazy_segtree<S,op,e,F,mapping,composition,id>> {\n    using Base = rb_tree_base<S,\
    \ rb_lazy_segtree_node<S,op,e,F,id>, rb_lazy_segtree<S,op,e,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::split, Base::merge, Base::size, Base::root;\n   \
    \ using ptr = rb_lazy_segtree_node<S,op,e,F,id>*;\n    static ptr before_erase(ptr\
    \ p) {\n        assert(p != nullptr);\n        if (p->lazy != id()) {\n      \
    \      p->l = applied(p->l, p->lazy);\n            p->r = applied(p->r, p->lazy);\n\
    \            p->lazy = id();\n        }\n        return p;\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n        if\
    \ (l == r) return e();\n\n        auto [a, tmp] = split(root, l);\n        auto\
    \ [c, b] = split(tmp, r-l);\n        S val = c->val;\n        root = merge(a,\
    \ merge(c, b));\n        return val;\n    }\n    void apply(int l, int r, F lazy)\
    \ {\n        assert(0 <= l and l <= r and r <= size());\n        if (l == r) return;\n\
    \n        auto [a, tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n\
    \        root = merge(a, merge(applied(c, lazy), b));\n    }\nprivate:\n    static\
    \ ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n       \
    \ p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n};\n\n\ntemplate<class S, S(*op)(S,S), S(*e)(),\
    \ class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct rb_lazy_segtree_reversible\
    \ : public rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>, rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,e,F,id>,\
    \ rb_lazy_segtree_reversible<S,op,e,F,mapping,composition,id>>;\n    using Base::Base,\
    \ Base::split, Base::merge, Base::size, Base::root;\n    using ptr = rb_lazy_segtree_reversible_node<S,op,e,F,id>*;\n\
    \    static ptr before_erase(ptr p) {\n        assert(p != nullptr);\n       \
    \ if (p->lazy != id()) {\n            p->l = applied(p->l, p->lazy);\n       \
    \     p->r = applied(p->r, p->lazy);\n            p->lazy = id();\n        }\n\
    \        if (p->rev) {\n            p->l = reversed(p->l);\n            p->r =\
    \ reversed(p->r);\n            p->rev = false;\n        }\n        return p;\n\
    \    }\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ size());\n        if (l == r) return e();\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        S val = c->val;\n     \
    \   root = merge(a, merge(c, b));\n        return val;\n    }\n    void apply(int\
    \ l, int r, F lazy) {\n        assert(0 <= l and l <= r and r <= size());\n  \
    \      if (l == r) return;\n\n        auto [a, tmp] = split(root, l);\n      \
    \  auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(applied(c, lazy),\
    \ b));\n    }\n    void reverse(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] =\
    \ split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a,\
    \ merge(reversed(c), b));\n    }\nprivate:\n    static ptr applied(ptr p, const\
    \ F& lazy) {\n        assert(p != nullptr);\n        p->val = mapping(lazy, p->val);\n\
    \        if (p->l) p->lazy = composition(p->lazy, lazy);\n        return p;\n\
    \    }\n    static ptr reversed(ptr p) {\n        assert(p != nullptr);\n    \
    \    std::swap(p->l, p->r);\n        if (p->l) p->rev ^= 1;\n        return p;\n\
    \    }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_RBTREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/rbtree.hpp
  requiredBy: []
  timestamp: '2021-10-25 07:59:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/redblacklazysegtree.test.cpp
documentation_of: atcoder/rbtree.hpp
layout: document
redirect_from:
- /library/atcoder/rbtree.hpp
- /library/atcoder/rbtree.hpp.html
title: atcoder/rbtree.hpp
---
