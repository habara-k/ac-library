---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistentsegtree.test.cpp
    title: test/persistentsegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/persistentsegtree.hpp\"\n\n#define ATCODER_PERSISTENTSEGTREE\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()>\nstruct PersistentSegmentTree {\n    struct Node;\n\
    \    using ptr = Node*;\n    struct Node {\n        ptr l=nullptr, r=nullptr;\n\
    \        S x;\n        explicit Node(S x_) : x(x_) {}\n        Node(ptr l_, ptr\
    \ r_) : l(l_), r(r_), x(op(l->x, r->x)) {}\n    };\n\n    int n = 0;\n\n    ptr\
    \ build(int n_) {\n        return build(std::vector<S>(n_, e()));\n    }\n   \
    \ ptr build(const std::vector<S>& v) {\n        n = (int)v.size();\n        return\
    \ build(0, n, v);\n    }\n\n    ptr set(ptr root, int k, const S& x) {\n     \
    \   assert(0 <= k and k < n);\n        return set(root, k, x, 0, n);\n    }\n\n\
    \    S prod(ptr root, int a, int b) {\n        assert(0 <= a and a <= b and b\
    \ <= n);\n        return prod(root, a, b, 0, n);\n    }\n\n    S get(ptr root,\
    \ int k) {\n        assert(0 <= k and k < n);\n        return prod(root, k, k\
    \ + 1);\n    }\n\nprivate:\n    ptr build(int l, int r, const std::vector<S>&\
    \ v) const {\n        assert(l < r);\n        if (l+1 == r) return new Node(v[l]);\n\
    \        return new Node(build(l, (l+r)>>1, v), build((l+r)>>1, r, v));\n    }\n\
    \    ptr set(ptr t, int k, const S& x, int l, int r) const {\n        assert(l\
    \ < r);\n        if (k == l and k+1 == r) return new Node(x);\n        if (r <=\
    \ k or k < l) return t;\n        return new Node(set(t->l, k, x, l, (l+r)>>1),\n\
    \                        set(t->r, k, x, (l+r)>>1, r));\n    }\n\n    S prod(ptr\
    \ t, int a, int b, int l, int r) const {\n        assert(l < r);\n        if (r\
    \ <= a or b <= l) return e();\n        if (a <= l and r <= b) return t->x;\n \
    \       return op(prod(t->l, a, b, l, (l+r)>>1),\n                  prod(t->r,\
    \ a, b, (l+r)>>1, r));\n    }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_PERSISTENTSEGTREE_HPP\n"
  code: "#ifndef ATCODER_PERSISTENTSEGTREE_HPP\n#define ATCODER_PERSISTENTSEGTREE\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()>\nstruct PersistentSegmentTree {\n    struct Node;\n\
    \    using ptr = Node*;\n    struct Node {\n        ptr l=nullptr, r=nullptr;\n\
    \        S x;\n        explicit Node(S x_) : x(x_) {}\n        Node(ptr l_, ptr\
    \ r_) : l(l_), r(r_), x(op(l->x, r->x)) {}\n    };\n\n    int n = 0;\n\n    ptr\
    \ build(int n_) {\n        return build(std::vector<S>(n_, e()));\n    }\n   \
    \ ptr build(const std::vector<S>& v) {\n        n = (int)v.size();\n        return\
    \ build(0, n, v);\n    }\n\n    ptr set(ptr root, int k, const S& x) {\n     \
    \   assert(0 <= k and k < n);\n        return set(root, k, x, 0, n);\n    }\n\n\
    \    S prod(ptr root, int a, int b) {\n        assert(0 <= a and a <= b and b\
    \ <= n);\n        return prod(root, a, b, 0, n);\n    }\n\n    S get(ptr root,\
    \ int k) {\n        assert(0 <= k and k < n);\n        return prod(root, k, k\
    \ + 1);\n    }\n\nprivate:\n    ptr build(int l, int r, const std::vector<S>&\
    \ v) const {\n        assert(l < r);\n        if (l+1 == r) return new Node(v[l]);\n\
    \        return new Node(build(l, (l+r)>>1, v), build((l+r)>>1, r, v));\n    }\n\
    \    ptr set(ptr t, int k, const S& x, int l, int r) const {\n        assert(l\
    \ < r);\n        if (k == l and k+1 == r) return new Node(x);\n        if (r <=\
    \ k or k < l) return t;\n        return new Node(set(t->l, k, x, l, (l+r)>>1),\n\
    \                        set(t->r, k, x, (l+r)>>1, r));\n    }\n\n    S prod(ptr\
    \ t, int a, int b, int l, int r) const {\n        assert(l < r);\n        if (r\
    \ <= a or b <= l) return e();\n        if (a <= l and r <= b) return t->x;\n \
    \       return op(prod(t->l, a, b, l, (l+r)>>1),\n                  prod(t->r,\
    \ a, b, (l+r)>>1, r));\n    }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_PERSISTENTSEGTREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/persistentsegtree.hpp
  requiredBy: []
  timestamp: '2021-10-25 15:36:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistentsegtree.test.cpp
documentation_of: atcoder/persistentsegtree.hpp
layout: document
title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要

永続化したセグメント木.

- `build(n)` : 長さ $n$ の配列を単位元 $e()$ で初期化し, 根のポインタを返す.
- `build(v)` : 配列 $v_1, \dots, v_n$ で初期化し, 根のポインタを返す.
- `set(p, k, x)` : ポインタ $p$ がさす時点の木に対して,
$k$ 番目(0-origin)の要素を $x$ に更新する.
その後, 根のポインタを返す.
- `get(p, k)` : ポインタ $p$ がさす時点の木に対して,
$k$ 番目(0-origin)の要素を返す.
- `get(p, a, b)` : ポインタ $p$ がさす時点の木に対して,
区間 $a, \ldots, b-1$ (0-origin)の総積を返す.

## 制約

- モノイドをのせる.

## 計算量

- 初期化 `build(n), build(v)` : $O(n)$
- クエリ `set, get` : $O(\log n)$
