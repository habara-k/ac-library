---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/rbtree_base.hpp
    title: "\u8D64\u9ED2\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/rb_segtree.hpp\"\n\n\n\n#line 1 \"atcoder/rbtree_base.hpp\"\
    \n\n\n\n#include <vector>\n#include <cassert>\n\n// References:\n// https://ei1333.github.io/library/other/vector-pool.cpp\n\
    \nnamespace atcoder {\n\ntemplate<class T>\nstruct VectorPool {\n    std::vector<T>\
    \ pool;\n    std::vector<T*> stock;\n    int size = 0;\n\n    explicit VectorPool(int\
    \ sz) : pool(sz), stock(sz) { clear(); }\n\n    template<typename... U>\n    T\
    \ *alloc(U... args) { return &(*stock[size++] = T(args...)); }\n\n    inline void\
    \ free(T *t) { (stock[--size] = t)->~T(); }\n\n    void clear() {\n        size\
    \ = 0;\n        for (int i = 0; i < (int)pool.size(); i++) stock[i] = &pool[i];\n\
    \    }\n};\n\n// References:\n// https://ei1333.github.io/library/structure/bbst/lazy-red-black-tree.cpp\n\
    // http://blog.mitaki28.info/1447078746296/\n// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // https://suisen-cp.github.io/cp-library-cpp/library/datastructure/lazy_eval_dynamic_sequence.hpp\n\
    \ntemplate<class S, class Derived>\nstruct rb_tree_node_base {\n    using ptr\
    \ = Derived*;\n    ptr l=nullptr, r=nullptr;\n    int size=1, rank=0;\n    bool\
    \ red=false;\n    S val;\n    rb_tree_node_base() = default;\n    explicit rb_tree_node_base(S\
    \ val_) : val(val_) {}\n    rb_tree_node_base(ptr l_, ptr r_, int red_) :\n  \
    \          l(l_), r(r_), size(l->size + r->size), rank(l->rank + !l->red), red(red_)\
    \ {}\n    bool isLeaf() { return l == nullptr; }\n};\n\ntemplate<class S, class\
    \ Node>\nstruct rb_tree_base {\n    using ptr = typename Node::ptr;\n    ptr root;\n\
    \    // Ensure: root is null or valid\n\n    // valid <=>\n    // - The root and\
    \ leaves are black\n    // - Red nodes are not adjacent\n    // - The number of\
    \ black nodes on the root-to-leaf path is constant\n\n    explicit rb_tree_base(int\
    \ max_n) : pool(2*max_n-1) {}\n\n    int size() { return sz(root); }\n\n    void\
    \ build(const std::vector<S>& v) {\n        root = build(v, 0, int(v.size()));\n\
    \    }\n\n    void insert(int k, S val) {\n        assert(0 <= k and k <= size());\n\
    \        auto [l, r] = split(root, k);\n        root = merge(merge(l, pool.alloc(val)),\
    \ r);\n    }\n\n    S erase(int k) {\n        assert(0 <= k and k < size());\n\
    \        auto [l, tmp] = split(root, k);\n        auto [c, r] = split(tmp, 1);\n\
    \        S val = c->val;\n        pool.free(c);\n        root = merge(l, r);\n\
    \        return val;\n    }\n\n    S get(int k) {\n        assert(0 <= k and k\
    \ < size());\n        auto [a, tmp] = split(root, k);\n        auto [c, b] = split(tmp,\
    \ 1);\n        S val = c->val;\n        root = merge(a, merge(c, b));\n      \
    \  return val;\n    }\n\n    ptr merge(ptr a, ptr b) {\n        // Require:\n\
    \        // - a, b: null or valid\n        if (!a) return b;\n        if (!b)\
    \ return a;\n        return asRoot(mergeSub(a, b));\n    }\n\n    std::pair<ptr,\
    \ ptr> split(ptr p, int k) {\n        // Require:\n        // - p: null or asRoot(p)\
    \ is valid\n        // Ensure:\n        // - returned nodes are null or valid\n\
    \        assert(0 <= k and k <= sz(p));\n        if (k == 0) return { nullptr,\
    \ p };\n        if (k == sz(p)) return { p, nullptr };\n        ptr l = p->l,\
    \ r = p->r;\n        pool.free(p);\n        if (k < sz(l)) {\n            auto\
    \ [a, b] = split(l, k);\n            return { a, merge(b, asRoot(r)) };\n    \
    \    }\n        if (k > sz(l)) {\n            auto [a, b] = split(r, k - sz(l));\n\
    \            return { merge(asRoot(l), a), b };\n        }\n        return { asRoot(l),\
    \ asRoot(r) };\n    }\n\nprivate:\n    static const bool RED = true, BLACK = false;\n\
    \n    VectorPool<Node> pool;\n\n    int sz(ptr p) { return p ? p->size : 0; }\n\
    \n    ptr build(const std::vector<S>& v, int l, int r) {\n        if (r - l ==\
    \ 1) return pool.alloc(v[l]);\n        return merge(build(v, l, (l+r)/2), build(v,\
    \ (l+r)/2, r));\n    }\n\n    ptr mergeSub(ptr a, ptr b) {\n        // Require:\n\
    \        // - asRoot(a), asRoot(b) is valid\n        // Ensure:\n        // -\
    \ asRoot(returned node) is valid\n        // - (returned node)->rank = max(a->rank,\
    \ b->rank)\n        assert(a != nullptr);\n        assert(b != nullptr);\n   \
    \     if (a->rank < b->rank or (a->rank == b->rank and b->red)) {\n          \
    \  ptr l = b->l, r = b->r;\n            bool red = b->red;\n            pool.free(b);\n\
    \            ptr c = mergeSub(a, l);\n            if (red or !c->red or !c->l->red)\
    \ return pool.alloc(c, r, red);\n            if (r->red) return pool.alloc(asRoot(c),\
    \ asRoot(r), RED);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n\
    \            return pool.alloc(cl, pool.alloc(cr, r, RED), BLACK);\n        }\n\
    \        if (a->rank > b->rank or (a->rank == b->rank and a->red)) {\n       \
    \     ptr l = a->l, r = a->r;\n            bool red = a->red;\n            pool.free(a);\n\
    \            ptr c = mergeSub(r, b);\n            if (red or !c->red or !c->r->red)\
    \ return pool.alloc(l, c, red);\n            if (l->red) return pool.alloc(asRoot(l),\
    \ asRoot(c), RED);\n            ptr cl = c->l, cr = c->r;\n            pool.free(c);\n\
    \            return pool.alloc(pool.alloc(l, cl, RED), cr, BLACK);\n        }\n\
    \        return pool.alloc(a, b, RED);\n    }\n\n    ptr asRoot(ptr p) {\n   \
    \     if (!p) return p;\n        p->red = BLACK;\n        return p;\n    }\n};\n\
    \n}  // namespace atcoder\n\n\n#line 5 \"atcoder/rb_segtree.hpp\"\n\nnamespace\
    \ atcoder {\n\ntemplate<class S, S(*op)(S,S)>\nstruct rb_segtree_node : public\
    \ rb_tree_node_base<S, rb_segtree_node<S, op>> {\n    using Base = rb_tree_node_base<S,\
    \ rb_segtree_node>;\n    using Base::Base;\n    using ptr = typename Base::ptr;\n\
    \    rb_segtree_node(ptr l_, ptr r_, int red_) : Base(l_, r_, red_) {\n      \
    \  Base::val = op(Base::l->val, Base::r->val);\n    }\n};\n\ntemplate<class S,\
    \ S(*op)(S,S), S(*e)()>\nstruct rb_segtree : public rb_tree_base<S, rb_segtree_node<S,op>>\
    \ {\n    using Node = rb_segtree_node<S,op>;\n    using Base = rb_tree_base<S,\
    \ Node>;\n    using Base::Base, Base::size;\nprivate:\n    using Base::split,\
    \ Base::merge, Base::root;\npublic:\n    S prod(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r <= size());\n        if (l == r) return e();\n\n     \
    \   auto [a, tmp] = split(root, l);\n        auto [c, b] = split(tmp, r-l);\n\
    \        S val = c->val;\n        root = merge(a, merge(c, b));\n        return\
    \ val;\n    }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_RB_SEGTREE_HPP\n#define ATCODER_RB_SEGTREE_HPP 1\n\n#include\
    \ \"atcoder/rbtree_base\"\n\nnamespace atcoder {\n\ntemplate<class S, S(*op)(S,S)>\n\
    struct rb_segtree_node : public rb_tree_node_base<S, rb_segtree_node<S, op>> {\n\
    \    using Base = rb_tree_node_base<S, rb_segtree_node>;\n    using Base::Base;\n\
    \    using ptr = typename Base::ptr;\n    rb_segtree_node(ptr l_, ptr r_, int\
    \ red_) : Base(l_, r_, red_) {\n        Base::val = op(Base::l->val, Base::r->val);\n\
    \    }\n};\n\ntemplate<class S, S(*op)(S,S), S(*e)()>\nstruct rb_segtree : public\
    \ rb_tree_base<S, rb_segtree_node<S,op>> {\n    using Node = rb_segtree_node<S,op>;\n\
    \    using Base = rb_tree_base<S, Node>;\n    using Base::Base, Base::size;\n\
    private:\n    using Base::split, Base::merge, Base::root;\npublic:\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n        if\
    \ (l == r) return e();\n\n        auto [a, tmp] = split(root, l);\n        auto\
    \ [c, b] = split(tmp, r-l);\n        S val = c->val;\n        root = merge(a,\
    \ merge(c, b));\n        return val;\n    }\n};\n\n}  // namespace atcoder\n\n\
    #endif  // ATCODER_RBTREE_BASE_HPP\n"
  dependsOn:
  - atcoder/rbtree_base.hpp
  isVerificationFile: false
  path: atcoder/rb_segtree.hpp
  requiredBy: []
  timestamp: '2021-10-28 14:52:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/rb_segtree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u8D64\u9ED2\u6728"
---

## 概要

挿入と削除が $O(\log n)$ でできるセグメント木.

- `insert(k, x)` : $k$ 番目に $x$ を挿入する.
- `erase(k)` : $k$ 番目の要素を削除する.
- `get(k)` : $k$ 番目の要素を取得する.
- `prod(l, r)` : 区間 $[l, r)$ に対応する総積を取得する.
- `build(v)` : 配列 $v$ で初期化する.


## 計算量

- `insert` : $O(\log n)$
- `erase` : $O(\log n)$
- `get` : $O(\log n)$
- `prod` : $O(\log n)$
- `build` : $O(n)$
