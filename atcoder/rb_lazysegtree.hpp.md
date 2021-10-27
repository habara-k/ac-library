---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/rbtree_base.hpp
    title: "\u8D64\u9ED2\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/redblacklazysegtree.test.cpp
    title: test/redblacklazysegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/rb_lazysegtree.hpp\"\n\n\n\n#line 1 \"atcoder/rbtree_base.hpp\"\
    \n\n\n\n#include <vector>\n#include <cassert>\n\n// References:\n// https://ei1333.github.io/library/other/vector-pool.cpp\n\
    \nnamespace atcoder {\n\ntemplate<class T>\nstruct VectorPool {\n    std::vector<T>\
    \ pool;\n    std::vector<T*> stock;\n    int size = 0;\n\n    VectorPool() = default;\n\
    \n    explicit VectorPool(int sz) : pool(sz), stock(sz) { clear(); }\n\n    template<typename...\
    \ U>\n    T *alloc(U... args) { return &(*stock[size++] = T(args...)); }\n\n \
    \   inline void free(T *t) { (stock[--size] = t)->~T(); }\n\n    void clear()\
    \ {\n        size = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i]\
    \ = &pool[i];\n    }\n};\n\n// References:\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \ntemplate<class S, class Derived>\nstruct rb_tree_node_base {\n    using ptr\
    \ = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int sz=1, rnk=0;\n    bool red=false;\n\
    \    S val;\n    rb_tree_node_base() = default;\n    explicit rb_tree_node_base(S\
    \ val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr r_, int red_) :\n  \
    \          l(l_), r(r_), sz(l->sz + r->sz), rnk(l->rnk + !l->red), red(red_) {}\n\
    \    bool isLeaf() { return l == nullptr; }\n};\n\ntemplate<class S, class Node>\n\
    struct rb_tree_base {\n    using ptr = Node*;\n    ptr root;\n    // Ensure: root\
    \ is null or valid\n\n    // valid <=>\n    // - The root and leaves are black\n\
    \    // - Red nodes are not adjacent\n    // - The number of black nodes on the\
    \ root-to-leaf path is constant\n\n    explicit rb_tree_base(int max_n) : pool(2*max_n-1)\
    \ {}\n\n    int size() { return sz(root); }\n\n    void build(const std::vector<S>&\
    \ v) {\n        root = build(v, 0, int(v.size()));\n    }\n\n    void insert(int\
    \ k, S val) {\n        assert(0 <= k and k <= size());\n        auto [l, r] =\
    \ split(root, k);\n        root = merge(merge(l, pool.alloc(val)), r);\n    }\n\
    \n    S erase(int k) {\n        assert(0 <= k and k < size());\n        auto [l,\
    \ tmp] = split(root, k);\n        auto [c, r] = split(tmp, 1);\n        S val\
    \ = c->val;\n        pool.free(c);\n        root = merge(l, r);\n        return\
    \ val;\n    }\n\n    S get(int k) {\n        assert(0 <= k and k < size());\n\
    \        auto [a, tmp] = split(root, k);\n        auto [c, b] = split(tmp, 1);\n\
    \        S val = c->val;\n        root = merge(a, merge(c, b));\n        return\
    \ val;\n    }\n\n    ptr merge(ptr a, ptr b) {\n        // Require:\n        //\
    \ - a, b: null or valid\n        if (!a) return b;\n        if (!b) return a;\n\
    \        return asRoot(mergeSub(a, b));\n    }\n\n    std::pair<ptr, ptr> split(ptr\
    \ p, int k) {\n        // Require:\n        // - p: null or asRoot(p) is valid\n\
    \        // Ensure:\n        // - returned nodes are null or valid\n        assert(0\
    \ <= k and k <= sz(p));\n        if (k == 0) return { nullptr, p };\n        if\
    \ (k == sz(p)) return { p, nullptr };\n        ptr l = p->l, r = p->r;\n     \
    \   pool.free(p);\n        if (k < sz(l)) {\n            auto [a, b] = split(l,\
    \ k);\n            return { a, merge(b, asRoot(r)) };\n        }\n        if (k\
    \ > sz(l)) {\n            auto [a, b] = split(r, k - sz(l));\n            return\
    \ { merge(asRoot(l), a), b };\n        }\n        return { asRoot(l), asRoot(r)\
    \ };\n    }\n\nprivate:\n    static const bool R = true, B = false;\n\n    VectorPool<Node>\
    \ pool;\n\n    int sz(ptr p) { return p ? p->sz : 0; }\n\n    ptr build(const\
    \ std::vector<S>& v, int l, int r) {\n        if (r - l == 1) return pool.alloc(v[l]);\n\
    \        return merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));\n    }\n\n\
    \    ptr mergeSub(ptr a, ptr b) {\n        // Require:\n        // - asRoot(a),\
    \ asRoot(b) is valid\n        // Ensure:\n        // - asRoot(returned node) is\
    \ valid\n        // - (returned node)->rnk = max(a->rnk, b->rnk)\n        assert(a\
    \ != nullptr);\n        assert(b != nullptr);\n        if (a->rnk < b->rnk or\
    \ (a->rnk == b->rnk and b->red)) {\n            ptr l = b->l, r = b->r;\n    \
    \        bool red = b->red;\n            pool.free(b);\n            ptr c = mergeSub(a,\
    \ l);\n            if (red or !c->red or !c->l->red) return pool.alloc(c, r, red);\n\
    \            if (r->red) return pool.alloc(asRoot(c), asRoot(r), R);\n       \
    \     ptr cl = c->l, cr = c->r;\n            pool.free(c);\n            return\
    \ pool.alloc(cl, pool.alloc(cr, r, R), B);\n        }\n        if (a->rnk > b->rnk\
    \ or (a->rnk == b->rnk and a->red)) {\n            ptr l = a->l, r = a->r;\n \
    \           bool red = a->red;\n            pool.free(a);\n            ptr c =\
    \ mergeSub(r, b);\n            if (red or !c->red or !c->r->red) return pool.alloc(l,\
    \ c, red);\n            if (l->red) return pool.alloc(asRoot(l), asRoot(c), R);\n\
    \            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n          \
    \  return pool.alloc(pool.alloc(l, cl, R), cr, B);\n        }\n        return\
    \ pool.alloc(a, b, R);\n    }\n\n    ptr asRoot(ptr p) {\n        if (!p) return\
    \ p;\n        p->red = B;\n        return p;\n    }\n};\n\n}  // namespace atcoder\n\
    \n\n#line 5 \"atcoder/rb_lazysegtree.hpp\"\n\nnamespace atcoder {\n\ntemplate<class\
    \ S, S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\n\
    struct rb_lazy_segtree_node : public rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_node_base<S, rb_lazy_segtree_node>;\n    using Base::Base,\
    \ Base::l, Base::r, Base::val, Base::isLeaf;\n    F lazy = id();\n    using ptr\
    \ = rb_lazy_segtree_node*;\n    rb_lazy_segtree_node(ptr l_, ptr r_, int red_)\
    \ : Base(l_, r_, red_) {\n        val = op(l->val, r->val);\n    }\n    ~rb_lazy_segtree_node()\
    \ {\n        if (lazy != id()) {\n            assert(!isLeaf());\n           \
    \ l = applied(l, lazy);\n            r = applied(r, lazy);\n        }\n    }\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (!p->isLeaf()) p->lazy =\
    \ composition(p->lazy, lazy);\n        return p;\n    }\n};\n\ntemplate<class\
    \ S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\n\
    struct rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_node<S,op,F,mapping,composition,id>;\n \
    \   using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::size;\nprivate:\n\
    \    using Base::split, Base::merge, Base::root;\npublic:\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l and l <= r and r <= size());\n        if (l == r)\
    \ return e();\n\n        auto [a, tmp] = split(root, l);\n        auto [c, b]\
    \ = split(tmp, r-l);\n        S val = c->val;\n        root = merge(a, merge(c,\
    \ b));\n        return val;\n    }\n    void apply(int l, int r, F lazy) {\n \
    \       assert(0 <= l and l <= r and r <= size());\n        if (l == r) return;\n\
    \n        auto [a, tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n\
    \        root = merge(a, merge(Node::applied(c, lazy), b));\n    }\n};\n\n}  //\
    \ namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_RB_LAZYSEGTREE_HPP\n#define ATCODER_RB_LAZYSEGTREE_HPP 1\n\
    \n#include \"atcoder/rbtree_base\"\n\nnamespace atcoder {\n\ntemplate<class S,\
    \ S(*op)(S,S), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\nstruct\
    \ rb_lazy_segtree_node : public rb_tree_node_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Base = rb_tree_node_base<S, rb_lazy_segtree_node>;\n    using Base::Base,\
    \ Base::l, Base::r, Base::val, Base::isLeaf;\n    F lazy = id();\n    using ptr\
    \ = rb_lazy_segtree_node*;\n    rb_lazy_segtree_node(ptr l_, ptr r_, int red_)\
    \ : Base(l_, r_, red_) {\n        val = op(l->val, r->val);\n    }\n    ~rb_lazy_segtree_node()\
    \ {\n        if (lazy != id()) {\n            assert(!isLeaf());\n           \
    \ l = applied(l, lazy);\n            r = applied(r, lazy);\n        }\n    }\n\
    \    static ptr applied(ptr p, const F& lazy) {\n        assert(p != nullptr);\n\
    \        p->val = mapping(lazy, p->val);\n        if (!p->isLeaf()) p->lazy =\
    \ composition(p->lazy, lazy);\n        return p;\n    }\n};\n\ntemplate<class\
    \ S, S(*op)(S,S), S(*e)(), class F, S(*mapping)(F,S), F(*composition)(F,F), F(*id)()>\n\
    struct rb_lazy_segtree : public rb_tree_base<S, rb_lazy_segtree_node<S,op,F,mapping,composition,id>>\
    \ {\n    using Node = rb_lazy_segtree_node<S,op,F,mapping,composition,id>;\n \
    \   using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::size;\nprivate:\n\
    \    using Base::split, Base::merge, Base::root;\npublic:\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l and l <= r and r <= size());\n        if (l == r)\
    \ return e();\n\n        auto [a, tmp] = split(root, l);\n        auto [c, b]\
    \ = split(tmp, r-l);\n        S val = c->val;\n        root = merge(a, merge(c,\
    \ b));\n        return val;\n    }\n    void apply(int l, int r, F lazy) {\n \
    \       assert(0 <= l and l <= r and r <= size());\n        if (l == r) return;\n\
    \n        auto [a, tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n\
    \        root = merge(a, merge(Node::applied(c, lazy), b));\n    }\n};\n\n}  //\
    \ namespace atcoder\n\n#endif  // ATCODER_RB_LAZYSEGTREE_HPP\n"
  dependsOn:
  - atcoder/rbtree_base.hpp
  isVerificationFile: false
  path: atcoder/rb_lazysegtree.hpp
  requiredBy: []
  timestamp: '2021-10-28 04:21:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/redblacklazysegtree.test.cpp
documentation_of: atcoder/rb_lazysegtree.hpp
layout: document
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u8D64\u9ED2\u6728"
---

## 概要

挿入と削除が $O(\log n)$ でできる遅延セグメント木.

- `insert(k, x)` : $k$ 番目に $x$ を挿入する.
- `erase(k)` : $k$ 番目の要素を削除する.
- `get(k)` : $k$ 番目の要素を取得する.
- `prod(l, r)` : 区間 $[l, r)$ に対応する総積を取得する.
- `apply(l, r, x)` : 区間 $[l, r)$ に 作用素 $x$ を適用する.
- `build(v)` : 配列 $v$ で初期化する.


## 計算量

- `insert` : $O(\log n)$
- `erase` : $O(\log n)$
- `get` : $O(\log n)$
- `prod` : $O(\log n)$
- `apply` : $O(\log n)$
- `build` : $O(n)$
