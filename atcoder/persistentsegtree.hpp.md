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
    \ 1\n\n#include <cassert>\n\nnamespace atcoder {\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct PersistentSegmentTree {\n    struct Node {\n        Node\
    \ *l, *r;\n        S x;\n        Node() : l(nullptr), r(nullptr) {}\n    };\n\n\
    \    const int sz;\n\n    explicit PersistentSegmentTree(int n) : sz(n) {}\n\n\
    \    Node* build() const {\n        return _build(0, sz);\n    }\n\n    Node*\
    \ set(Node* root, int pos, const S& x) const {\n        assert(0 <= pos and pos\
    \ < sz);\n        return _set(root, pos, x, 0, sz);\n    }\n\n    S prod(Node*\
    \ root, int a, int b) const {\n        assert(0 <= a and a <= b and b <= sz);\n\
    \        return _prod(root, a, b, 0, sz);\n    }\n\n    S get(Node* root, int\
    \ pos) const {\n        assert(0 <= pos and pos < sz);\n        return prod(root,\
    \ pos, pos + 1);\n    }\n\nprivate:\n    Node* _new(const S& x) const {\n    \
    \    auto t = new Node();\n        t->x = x;\n        return t;\n    }\n\n   \
    \ Node* _new(Node* l, Node* r) const {\n        auto t = new Node();\n       \
    \ t->l = l, t->r = r, t->x = op(l->x, r->x);\n        return t;\n    }\n\n   \
    \ Node* _build(int l, int r) const {\n        assert(l < r);\n        if (l+1\
    \ == r) return _new(e());\n        return _new(_build(l, (l+r)>>1), _build((l+r)>>1,\
    \ r));\n    }\n    Node* _set(Node* t, int pos, const S& x, int l, int r) const\
    \ {\n        assert(l < r);\n        if (pos == l and pos+1 == r) return _new(x);\n\
    \        if (r <= pos or pos < l) return t;\n        return _new(_set(t->l, pos,\
    \ x, l, (l+r)>>1),\n                    _set(t->r, pos, x, (l+r)>>1, r));\n  \
    \  }\n\n    S _prod(Node* t, int a, int b, int l, int r) const {\n        assert(l\
    \ < r);\n        if (r <= a or b <= l) return e();\n        if (a <= l and r <=\
    \ b) return t->x;\n        return op(_prod(t->l, a, b, l, (l+r)>>1),\n       \
    \           _prod(t->r, a, b, (l+r)>>1, r));\n    }\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_PERSISTENTSEGTREE_HPP\n"
  code: "#ifndef ATCODER_PERSISTENTSEGTREE_HPP\n#define ATCODER_PERSISTENTSEGTREE\
    \ 1\n\n#include <cassert>\n\nnamespace atcoder {\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct PersistentSegmentTree {\n    struct Node {\n        Node\
    \ *l, *r;\n        S x;\n        Node() : l(nullptr), r(nullptr) {}\n    };\n\n\
    \    const int sz;\n\n    explicit PersistentSegmentTree(int n) : sz(n) {}\n\n\
    \    Node* build() const {\n        return _build(0, sz);\n    }\n\n    Node*\
    \ set(Node* root, int pos, const S& x) const {\n        assert(0 <= pos and pos\
    \ < sz);\n        return _set(root, pos, x, 0, sz);\n    }\n\n    S prod(Node*\
    \ root, int a, int b) const {\n        assert(0 <= a and a <= b and b <= sz);\n\
    \        return _prod(root, a, b, 0, sz);\n    }\n\n    S get(Node* root, int\
    \ pos) const {\n        assert(0 <= pos and pos < sz);\n        return prod(root,\
    \ pos, pos + 1);\n    }\n\nprivate:\n    Node* _new(const S& x) const {\n    \
    \    auto t = new Node();\n        t->x = x;\n        return t;\n    }\n\n   \
    \ Node* _new(Node* l, Node* r) const {\n        auto t = new Node();\n       \
    \ t->l = l, t->r = r, t->x = op(l->x, r->x);\n        return t;\n    }\n\n   \
    \ Node* _build(int l, int r) const {\n        assert(l < r);\n        if (l+1\
    \ == r) return _new(e());\n        return _new(_build(l, (l+r)>>1), _build((l+r)>>1,\
    \ r));\n    }\n    Node* _set(Node* t, int pos, const S& x, int l, int r) const\
    \ {\n        assert(l < r);\n        if (pos == l and pos+1 == r) return _new(x);\n\
    \        if (r <= pos or pos < l) return t;\n        return _new(_set(t->l, pos,\
    \ x, l, (l+r)>>1),\n                    _set(t->r, pos, x, (l+r)>>1, r));\n  \
    \  }\n\n    S _prod(Node* t, int a, int b, int l, int r) const {\n        assert(l\
    \ < r);\n        if (r <= a or b <= l) return e();\n        if (a <= l and r <=\
    \ b) return t->x;\n        return op(_prod(t->l, a, b, l, (l+r)>>1),\n       \
    \           _prod(t->r, a, b, (l+r)>>1, r));\n    }\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_PERSISTENTSEGTREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/persistentsegtree.hpp
  requiredBy: []
  timestamp: '2021-07-15 20:09:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistentsegtree.test.cpp
documentation_of: atcoder/persistentsegtree.hpp
layout: document
redirect_from:
- /library/atcoder/persistentsegtree.hpp
- /library/atcoder/persistentsegtree.hpp.html
title: atcoder/persistentsegtree.hpp
---
