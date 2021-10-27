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
    \ sz) : pool(sz), stock(sz) { clear(); }\n\n    template<typename... U>\n    T\
    \ *alloc(U... args) { return &(*stock[size++] = T(args...)); }\n\n    inline void\
    \ free(T *t) { (stock[--size] = t)->~T(); }\n\n    void clear() {\n        size\
    \ = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i] = &pool[i];\n\
    \    }\n};\n\n// Inspired by\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \n\n// Base Class\n// Node\ntemplate<class S, class Derived>\nstruct rb_tree_node_base\
    \ {\n    using ptr = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int sz=1, rnk=0;\n\
    \    bool red=false;\n    S val;\n    rb_tree_node_base() = default;\n    explicit\
    \ rb_tree_node_base(S val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr\
    \ r_, int red_) :\n        l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red),\
    \ red(red_) {}\n};\n\n// Tree\ntemplate<class S, class Node>\nstruct rb_tree_base\
    \ {\n    explicit rb_tree_base(int max_n) : pool(2*max_n-1) {}\n\n    int size()\
    \ { return size(root); }\n\n    void build(const std::vector<S>& v) {\n      \
    \  root = build(v, 0, int(v.size()));\n    }\n\n    void insert(int k, S val)\
    \ {\n        assert(0 <= k and k <= size());\n        auto [l, r] = split(root,\
    \ k);\n        root = merge(merge(l, pool.alloc(val)), r);\n    }\n\n    S erase(int\
    \ k) {\n        assert(0 <= k and k < size());\n        auto [l, tmp] = split(root,\
    \ k);\n        auto [c, r] = split(tmp, 1);\n        S val = c->val;\n       \
    \ pool.free(c);\n        root = merge(l, r);\n        return val;\n    }\n\n \
    \   S get(int k) {\n        assert(0 <= k and k < size());\n        auto [a, tmp]\
    \ = split(root, k);\n        auto [c, b] = split(tmp, 1);\n        S val = c->val;\n\
    \        root = merge(a, merge(c, b));\n        return val;\n    }\n\n    static\
    \ const bool R = true, B = false;\n\n    VectorPool<Node> pool;\n\n    using ptr\
    \ = Node*;\n    ptr root;\n\n    int size(ptr p) { return p ? p->sz : 0; }\n\n\
    \    ptr merge(ptr a, ptr b) {\n        if (!a) return b;\n        if (!b) return\
    \ a;\n        ptr c = mergeSub(a, b);\n        return asRoot(c);\n    }\n\n  \
    \  std::pair<ptr, ptr> split(ptr p, int k) {\n        assert(0 <= k and k <= size(p));\n\
    \        if (k == 0) return { nullptr, p };\n        if (k == size(p)) return\
    \ { p, nullptr };\n        ptr l = p->l, r = p->r;\n        pool.free(p);\n  \
    \      if (k < size(l)) {\n            auto [a, b] = split(l, k);\n          \
    \  return { a, merge(b, asRoot(r)) };\n        }\n        if (k > size(l)) {\n\
    \            auto [a, b] = split(r, k - size(l));\n            return { merge(asRoot(l),\
    \ a), b };\n        }\n        return { asRoot(l), asRoot(r) };\n    }\n\n   \
    \ ptr build(const std::vector<S>& v, int l, int r) {\n        if (r - l == 1)\
    \ return pool.alloc(v[l]);\n        return merge(build(v, l, (l+r)/2), build(v,\
    \ (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n        assert(a !=\
    \ nullptr);\n        assert(b != nullptr);\n        if (a->rnk < b->rnk) {\n \
    \           ptr l = b->l, r = b->r;\n            bool red = b->red;\n        \
    \    pool.free(b);\n\n            ptr c = mergeSub(a, l);\n            if (red\
    \ or !c->red or !c->l->red) return pool.alloc(c, r, red);\n            if (r->red)\
    \ return pool.alloc(asRoot(c), asRoot(r), R);\n            ptr cl = c->l, cr =\
    \ c->r;\n            pool.free(c);\n            return pool.alloc(cl, pool.alloc(cr,\
    \ r, R), B);\n        }\n        if (a->rnk > b->rnk) {\n            ptr l = a->l,\
    \ r = a->r;\n            bool red = a->red;\n            pool.free(a);\n\n   \
    \         ptr c = mergeSub(r, b);\n            if (red or !c->red or !c->r->red)\
    \ return pool.alloc(l, c, red);\n            if (l->red) return pool.alloc(asRoot(l),\
    \ asRoot(c), R);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n\
    \            return pool.alloc(pool.alloc(l, cl, R), cr, B);\n        }\n    \
    \    return pool.alloc(a, b, R);\n    }\n\n    ptr asRoot(ptr p) {\n        if\
    \ (!p) return p;\n        p->red = B;\n        return p;\n    }\n};\n// End of\
    \ Base Class\n\n\n// Segtree\n// Node\ntemplate<class S, S(*op)(S,S)>\nstruct\
    \ rb_segtree_node : public rb_tree_node_base<S, rb_segtree_node<S, op>> {\n  \
    \  using Base = rb_tree_node_base<S, rb_segtree_node<S, op>>;\n    using Base::Base;\n\
    \    rb_segtree_node(rb_segtree_node *l_, rb_segtree_node *r_, int red_) : Base(l_,\
    \ r_, red_) {\n        Base::val = op(Base::l->val,Base::r->val);\n    }\n};\n\
    \n// Tree\ntemplate<class S, S(*op)(S,S), S(*e)()>\nstruct rb_segtree : public\
    \ rb_tree_base<S, rb_segtree_node<S,op>> {\n    using Node = rb_segtree_node<S,op>;\n\
    \    using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    };\n// End of Segtree\n\n\n// Lazy Segtree\n// Node\ntemplate<class S, S(*op)(S,S),\
    \ class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct rb_lazy_segtree_node\
    \ : public rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::l, Base::r, Base::val;\n    F lazy = id();\n    rb_lazy_segtree_node(rb_lazy_segtree_node\
    \ *l_, rb_lazy_segtree_node *r_, int red_) : Base(l_, r_, red_) {\n        Base::val\
    \ = op(Base::l->val,Base::r->val);\n    }\n    ~rb_lazy_segtree_node() {\n   \
    \     if (lazy != id()) {\n            l = applied(l, lazy);\n            r =\
    \ applied(r, lazy);\n        }\n    }\n    using ptr = rb_lazy_segtree_node<S,op,F,mapping,composition,id>*;\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n};\n\n// Tree\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct\
    \ rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_node<S,op,F,mapping,composition,id>;\n \
    \   using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    \    void apply(int l, int r, F lazy) {\n        assert(0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(Node::applied(c,\
    \ lazy), b));\n    }\n};\n// End of Lazy Segtree\n\n\n// Lazy Segtree Reversible\n\
    template<class S, S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F),\
    \ F(*id)()>\nstruct rb_lazy_segtree_reversible_node : public rb_tree_node_base<S,\
    \ rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>> {\n    using\
    \ Base = rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::l, Base::r, Base::val;\n    F lazy = id();\n    bool\
    \ rev = false;\n    rb_lazy_segtree_reversible_node(rb_lazy_segtree_reversible_node\
    \ *l_, rb_lazy_segtree_reversible_node *r_, int red_) :\n        Base(l_, r_,\
    \ red_) { Base::val = op(Base::l->val,Base::r->val); }\n    ~rb_lazy_segtree_reversible_node()\
    \ {\n        if (lazy != id()) {\n            l = applied(l, lazy);\n        \
    \    r = applied(r, lazy);\n        }\n        if (rev) {\n            l = reversed(l);\n\
    \            r = reversed(r);\n        }\n    }\n    using ptr = rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>*;\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n    static ptr reversed(ptr p) {\n       \
    \ assert(p != nullptr);\n        std::swap(p->l, p->r);\n        if (p->l) p->rev\
    \ ^= 1;\n        return p;\n    }\n};\n\n// Tree\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct\
    \ rb_lazy_segtree_reversible : public rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>;\n\
    \    using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    \    void apply(int l, int r, F lazy) {\n        assert(0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(Node::applied(c,\
    \ lazy), b));\n    }\n    void reverse(int l, int r) {\n        assert(0 <= l\
    \ and l <= r and r <= size());\n        if (l == r) return;\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        root\
    \ = merge(a, merge(Node::reversed(c), b));\n    }\n};\n// End of Lazy Segtree\
    \ Reversible\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_RBTREE_HPP\n#define ATCODER_RBTREE_HPP 1\n\n#include <cassert>\n\
    #include <vector>\n#include <iostream>\n\nnamespace atcoder {\n\n// https://ei1333.github.io/library/other/vector-pool.cpp\n\
    template<class T>\nstruct VectorPool {\n    std::vector<T> pool;\n    std::vector<T*>\
    \ stock;\n    int size = 0;\n\n    VectorPool() = default;\n\n    explicit VectorPool(int\
    \ sz) : pool(sz), stock(sz) { clear(); }\n\n    template<typename... U>\n    T\
    \ *alloc(U... args) { return &(*stock[size++] = T(args...)); }\n\n    inline void\
    \ free(T *t) { (stock[--size] = t)->~T(); }\n\n    void clear() {\n        size\
    \ = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i] = &pool[i];\n\
    \    }\n};\n\n// Inspired by\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \n\n// Base Class\n// Node\ntemplate<class S, class Derived>\nstruct rb_tree_node_base\
    \ {\n    using ptr = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int sz=1, rnk=0;\n\
    \    bool red=false;\n    S val;\n    rb_tree_node_base() = default;\n    explicit\
    \ rb_tree_node_base(S val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr\
    \ r_, int red_) :\n        l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red),\
    \ red(red_) {}\n};\n\n// Tree\ntemplate<class S, class Node>\nstruct rb_tree_base\
    \ {\n    explicit rb_tree_base(int max_n) : pool(2*max_n-1) {}\n\n    int size()\
    \ { return size(root); }\n\n    void build(const std::vector<S>& v) {\n      \
    \  root = build(v, 0, int(v.size()));\n    }\n\n    void insert(int k, S val)\
    \ {\n        assert(0 <= k and k <= size());\n        auto [l, r] = split(root,\
    \ k);\n        root = merge(merge(l, pool.alloc(val)), r);\n    }\n\n    S erase(int\
    \ k) {\n        assert(0 <= k and k < size());\n        auto [l, tmp] = split(root,\
    \ k);\n        auto [c, r] = split(tmp, 1);\n        S val = c->val;\n       \
    \ pool.free(c);\n        root = merge(l, r);\n        return val;\n    }\n\n \
    \   S get(int k) {\n        assert(0 <= k and k < size());\n        auto [a, tmp]\
    \ = split(root, k);\n        auto [c, b] = split(tmp, 1);\n        S val = c->val;\n\
    \        root = merge(a, merge(c, b));\n        return val;\n    }\n\n    static\
    \ const bool R = true, B = false;\n\n    VectorPool<Node> pool;\n\n    using ptr\
    \ = Node*;\n    ptr root;\n\n    int size(ptr p) { return p ? p->sz : 0; }\n\n\
    \    ptr merge(ptr a, ptr b) {\n        if (!a) return b;\n        if (!b) return\
    \ a;\n        ptr c = mergeSub(a, b);\n        return asRoot(c);\n    }\n\n  \
    \  std::pair<ptr, ptr> split(ptr p, int k) {\n        assert(0 <= k and k <= size(p));\n\
    \        if (k == 0) return { nullptr, p };\n        if (k == size(p)) return\
    \ { p, nullptr };\n        ptr l = p->l, r = p->r;\n        pool.free(p);\n  \
    \      if (k < size(l)) {\n            auto [a, b] = split(l, k);\n          \
    \  return { a, merge(b, asRoot(r)) };\n        }\n        if (k > size(l)) {\n\
    \            auto [a, b] = split(r, k - size(l));\n            return { merge(asRoot(l),\
    \ a), b };\n        }\n        return { asRoot(l), asRoot(r) };\n    }\n\n   \
    \ ptr build(const std::vector<S>& v, int l, int r) {\n        if (r - l == 1)\
    \ return pool.alloc(v[l]);\n        return merge(build(v, l, (l+r)/2), build(v,\
    \ (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n        assert(a !=\
    \ nullptr);\n        assert(b != nullptr);\n        if (a->rnk < b->rnk) {\n \
    \           ptr l = b->l, r = b->r;\n            bool red = b->red;\n        \
    \    pool.free(b);\n\n            ptr c = mergeSub(a, l);\n            if (red\
    \ or !c->red or !c->l->red) return pool.alloc(c, r, red);\n            if (r->red)\
    \ return pool.alloc(asRoot(c), asRoot(r), R);\n            ptr cl = c->l, cr =\
    \ c->r;\n            pool.free(c);\n            return pool.alloc(cl, pool.alloc(cr,\
    \ r, R), B);\n        }\n        if (a->rnk > b->rnk) {\n            ptr l = a->l,\
    \ r = a->r;\n            bool red = a->red;\n            pool.free(a);\n\n   \
    \         ptr c = mergeSub(r, b);\n            if (red or !c->red or !c->r->red)\
    \ return pool.alloc(l, c, red);\n            if (l->red) return pool.alloc(asRoot(l),\
    \ asRoot(c), R);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n\
    \            return pool.alloc(pool.alloc(l, cl, R), cr, B);\n        }\n    \
    \    return pool.alloc(a, b, R);\n    }\n\n    ptr asRoot(ptr p) {\n        if\
    \ (!p) return p;\n        p->red = B;\n        return p;\n    }\n};\n// End of\
    \ Base Class\n\n\n// Segtree\n// Node\ntemplate<class S, S(*op)(S,S)>\nstruct\
    \ rb_segtree_node : public rb_tree_node_base<S, rb_segtree_node<S, op>> {\n  \
    \  using Base = rb_tree_node_base<S, rb_segtree_node<S, op>>;\n    using Base::Base;\n\
    \    rb_segtree_node(rb_segtree_node *l_, rb_segtree_node *r_, int red_) : Base(l_,\
    \ r_, red_) {\n        Base::val = op(Base::l->val,Base::r->val);\n    }\n};\n\
    \n// Tree\ntemplate<class S, S(*op)(S,S), S(*e)()>\nstruct rb_segtree : public\
    \ rb_tree_base<S, rb_segtree_node<S,op>> {\n    using Node = rb_segtree_node<S,op>;\n\
    \    using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    };\n// End of Segtree\n\n\n// Lazy Segtree\n// Node\ntemplate<class S, S(*op)(S,S),\
    \ class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct rb_lazy_segtree_node\
    \ : public rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::l, Base::r, Base::val;\n    F lazy = id();\n    rb_lazy_segtree_node(rb_lazy_segtree_node\
    \ *l_, rb_lazy_segtree_node *r_, int red_) : Base(l_, r_, red_) {\n        Base::val\
    \ = op(Base::l->val,Base::r->val);\n    }\n    ~rb_lazy_segtree_node() {\n   \
    \     if (lazy != id()) {\n            l = applied(l, lazy);\n            r =\
    \ applied(r, lazy);\n        }\n    }\n    using ptr = rb_lazy_segtree_node<S,op,F,mapping,composition,id>*;\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n};\n\n// Tree\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct\
    \ rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_node<S,op,F,mapping,composition,id>;\n \
    \   using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    \    void apply(int l, int r, F lazy) {\n        assert(0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(Node::applied(c,\
    \ lazy), b));\n    }\n};\n// End of Lazy Segtree\n\n\n// Lazy Segtree Reversible\n\
    template<class S, S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F),\
    \ F(*id)()>\nstruct rb_lazy_segtree_reversible_node : public rb_tree_node_base<S,\
    \ rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>> {\n    using\
    \ Base = rb_tree_node_base<S, rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>>;\n\
    \    using Base::Base, Base::l, Base::r, Base::val;\n    F lazy = id();\n    bool\
    \ rev = false;\n    rb_lazy_segtree_reversible_node(rb_lazy_segtree_reversible_node\
    \ *l_, rb_lazy_segtree_reversible_node *r_, int red_) :\n        Base(l_, r_,\
    \ red_) { Base::val = op(Base::l->val,Base::r->val); }\n    ~rb_lazy_segtree_reversible_node()\
    \ {\n        if (lazy != id()) {\n            l = applied(l, lazy);\n        \
    \    r = applied(r, lazy);\n        }\n        if (rev) {\n            l = reversed(l);\n\
    \            r = reversed(r);\n        }\n    }\n    using ptr = rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>*;\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (p->l) p->lazy = composition(p->lazy,\
    \ lazy);\n        return p;\n    }\n    static ptr reversed(ptr p) {\n       \
    \ assert(p != nullptr);\n        std::swap(p->l, p->r);\n        if (p->l) p->rev\
    \ ^= 1;\n        return p;\n    }\n};\n\n// Tree\ntemplate<class S, S(*op)(S,S),\
    \ S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct\
    \ rb_lazy_segtree_reversible : public rb_tree_base<S, rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_reversible_node<S,op,F,mapping,composition,id>;\n\
    \    using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::split, Base::merge,\
    \ Base::size, Base::root;\n    S prod(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        if (l == r) return e();\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        S val\
    \ = c->val;\n        root = merge(a, merge(c, b));\n        return val;\n    }\n\
    \    void apply(int l, int r, F lazy) {\n        assert(0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return;\n\n        auto [a, tmp] = split(root,\
    \ l);\n        auto [c, b] = split(tmp, r-l);\n        root = merge(a, merge(Node::applied(c,\
    \ lazy), b));\n    }\n    void reverse(int l, int r) {\n        assert(0 <= l\
    \ and l <= r and r <= size());\n        if (l == r) return;\n\n        auto [a,\
    \ tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n        root\
    \ = merge(a, merge(Node::reversed(c), b));\n    }\n};\n// End of Lazy Segtree\
    \ Reversible\n\n}  // namespace atcoder\n\n#endif  // ATCODER_RBTREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/rbtree.hpp
  requiredBy: []
  timestamp: '2021-10-27 20:07:31+09:00'
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
