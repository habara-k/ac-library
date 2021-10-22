---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"atcoder/redblacklazysegtree.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace atcoder {\n\ntemplate<\n        class S,\n    \
    \    S (*op)(S,S),\n        S (*e)(),\n        class F,\n        S (*mapping)(S,\
    \ F),\n        F (*composition)(F, F),\n        F (*id)(),\n        int POOL>\n\
    struct RedBlackLazySegmentTree {\n    RedBlackLazySegmentTree() : pool(POOL),\
    \ stock(POOL) { clear(); }\n\n    static const bool R = false, B = true;\n   \
    \ struct node {\n        node *l=nullptr, *r=nullptr;\n        S prd = e();\n\
    \        F lazy = id();\n        int sz=1, rnk=0;\n        bool color=B;\n   \
    \     node() = default;\n        explicit node(S val) : prd(val) {}\n        node(node\
    \ *l_, node *r_, int color_) : l(l_), r(r_), prd(op(l->prd,r->prd)),\n       \
    \                                     sz(l->sz + r->sz), rnk(l->rnk + l->color),\
    \ color(color_) {}\n    };\n    int size() { return size(root); }\n    int size(node\
    \ *p) { return p ? p->sz : 0; }\n\n    void build(const std::vector<S>& v) {\n\
    \        root = build(v, 0, int(v.size()));\n    }\n\n    node* merge(node *a,\
    \ node *b) {\n        if (!a) return b;\n        if (!b) return a;\n        auto\
    \ c = merge_sub(a, b);\n        return as_root(c);\n    }\n    std::pair<node*,\
    \ node*> split(node *a, int k) {\n        assert(0 <= k and k <= size(a));\n \
    \       if (k == 0) return {nullptr, a};\n        if (k == size(a)) return {a,\
    \ nullptr};\n        a = push(a);\n        node *l = a->l, *r = a->r;\n      \
    \  del(a);\n        if (k < l->sz) {\n            auto p = split(l, k);\n    \
    \        return {p.first, merge(p.second, as_root(r))};\n        }\n        if\
    \ (k > l->sz) {\n            auto p = split(r, k - l->sz);\n            return\
    \ {merge(as_root(l), p.first), p.second};\n        }\n        return {as_root(l),\
    \ as_root(r)};\n    }\n\n    void insert(int k, S val) {\n        assert(0 <=\
    \ k and k <= size());\n        auto p = split(root, k);\n        root = merge(merge(p.first,\
    \ alloc(val)), p.second);\n    }\n    S erase(int k) {\n        assert(0 <= k\
    \ and k < size());\n        auto p = split(root, k);\n        auto q = split(p.second,\
    \ 1);\n        S val = q.first->prd;\n        del(q.first);\n        root = merge(p.first,\
    \ q.second);\n        return val;\n    }\n\n    S prod(int l, int r) {\n     \
    \   assert(0 <= l and l <= r and r <= size());\n        return prod(root, 0, root->sz,\
    \ id(), l, r);\n    }\n    S get(int k) {\n        assert(0 <= k and k < size());\n\
    \        return prod(k, k+1);\n    }\n    void apply(int l, int r, F lazy) {\n\
    \        assert(0 <= l and l <= r and r <= size());\n        auto p = split(root,\
    \ l);\n        auto q = split(p.second, r-l);\n        root = merge(p.first, merge(set_lazy(q.first,\
    \ lazy), q.second));\n    }\n    node* root;\n\nprotected:\n\n    std::vector<node>\
    \ pool;\n    std::vector<node*> stock;\n    int head = POOL;\n\n    template<typename...\
    \ U>\n    node* alloc(U... args) {\n        return &(*stock[--head] = node(args...));\n\
    \    }\n    void del(node* p) {\n        stock[head++] = p;\n    }\n    void clear()\
    \ {\n        head = POOL;\n        for (int i = 0; i < POOL; ++i) stock[i] = &pool[i];\n\
    \    }\n\n    node* set_lazy(node* p, const F& lazy) {\n        p->prd = mapping(lazy,\
    \ p->prd);\n        if (p->l) p->lazy = composition(p->lazy, lazy);\n        return\
    \ p;\n    }\n\n    node* push(node *p) {\n        if (p->lazy == id()) return\
    \ p;\n        p->l = set_lazy(p->l, p->lazy);\n        p->r = set_lazy(p->r, p->lazy);\n\
    \        p->lazy = id();\n        return p;\n    }\n\n    node* build(const std::vector<S>&\
    \ v, int l, int r) {\n        if (r - l == 1) return alloc(v[l]);\n        return\
    \ merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));\n    }\n\n    node* merge_sub(node\
    \ *a, node *b) {\n        if (a->rnk < b->rnk) {\n            b = push(b);\n \
    \           auto c = merge_sub(a, b->l);\n            node *ret;\n           \
    \ if (b->color and !c->color and !c->l->color) {\n                if (b->r->color)\
    \ ret = alloc(c->l, alloc(c->r, b->r, R), B), del(c);\n                else ret\
    \ = alloc(as_root(c), as_root(b->r), R);\n            } else {\n             \
    \   ret = alloc(c, b->r, b->color);\n            }\n            del(b); return\
    \ ret;\n        } else if (a->rnk > b->rnk) {\n            a = push(a);\n    \
    \        auto c = merge_sub(a->r, b);\n            node *ret;\n            if\
    \ (a->color and !c->color and !c->r->color) {\n                if (a->l->color)\
    \ ret = alloc(alloc(a->l, c->l, R), c->r, B), del(c);\n                else ret\
    \ = alloc(as_root(a->l), as_root(c), R);\n            } else {\n             \
    \   ret = alloc(a->l, c, a->color);\n            }\n            del(a); return\
    \ ret;\n        } else {\n            return alloc(a, b, R);\n        }\n    }\n\
    \n    node* as_root(node *p) {\n        if (!p or p->color) return p;\n      \
    \  p->color = B;\n        return p;\n    }\n\n    S prod(node *p, int a, int b,\
    \ F lazy, int l, int r) {\n        if (b <= l or r <= a) return e();\n       \
    \ if (l <= a and b <= r) return mapping(lazy, p->prd);\n        return op(prod(p->l,\
    \ a, a + p->l->sz, composition(p->lazy, lazy), l, r),\n                  prod(p->r,\
    \ b - p->r->sz, b, composition(p->lazy, lazy), l, r));\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_REDBLACKLAZYSEGTREE_HPP\n#define ATCODER_REDBLACKLAZYSEGTREE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\ntemplate<\n\
    \        class S,\n        S (*op)(S,S),\n        S (*e)(),\n        class F,\n\
    \        S (*mapping)(S, F),\n        F (*composition)(F, F),\n        F (*id)(),\n\
    \        int POOL>\nstruct RedBlackLazySegmentTree {\n    RedBlackLazySegmentTree()\
    \ : pool(POOL), stock(POOL) { clear(); }\n\n    static const bool R = false, B\
    \ = true;\n    struct node {\n        node *l=nullptr, *r=nullptr;\n        S\
    \ prd = e();\n        F lazy = id();\n        int sz=1, rnk=0;\n        bool color=B;\n\
    \        node() = default;\n        explicit node(S val) : prd(val) {}\n     \
    \   node(node *l_, node *r_, int color_) : l(l_), r(r_), prd(op(l->prd,r->prd)),\n\
    \                                            sz(l->sz + r->sz), rnk(l->rnk + l->color),\
    \ color(color_) {}\n    };\n    int size() { return size(root); }\n    int size(node\
    \ *p) { return p ? p->sz : 0; }\n\n    void build(const std::vector<S>& v) {\n\
    \        root = build(v, 0, int(v.size()));\n    }\n\n    node* merge(node *a,\
    \ node *b) {\n        if (!a) return b;\n        if (!b) return a;\n        auto\
    \ c = merge_sub(a, b);\n        return as_root(c);\n    }\n    std::pair<node*,\
    \ node*> split(node *a, int k) {\n        assert(0 <= k and k <= size(a));\n \
    \       if (k == 0) return {nullptr, a};\n        if (k == size(a)) return {a,\
    \ nullptr};\n        a = push(a);\n        node *l = a->l, *r = a->r;\n      \
    \  del(a);\n        if (k < l->sz) {\n            auto p = split(l, k);\n    \
    \        return {p.first, merge(p.second, as_root(r))};\n        }\n        if\
    \ (k > l->sz) {\n            auto p = split(r, k - l->sz);\n            return\
    \ {merge(as_root(l), p.first), p.second};\n        }\n        return {as_root(l),\
    \ as_root(r)};\n    }\n\n    void insert(int k, S val) {\n        assert(0 <=\
    \ k and k <= size());\n        auto p = split(root, k);\n        root = merge(merge(p.first,\
    \ alloc(val)), p.second);\n    }\n    S erase(int k) {\n        assert(0 <= k\
    \ and k < size());\n        auto p = split(root, k);\n        auto q = split(p.second,\
    \ 1);\n        S val = q.first->prd;\n        del(q.first);\n        root = merge(p.first,\
    \ q.second);\n        return val;\n    }\n\n    S prod(int l, int r) {\n     \
    \   assert(0 <= l and l <= r and r <= size());\n        return prod(root, 0, root->sz,\
    \ id(), l, r);\n    }\n    S get(int k) {\n        assert(0 <= k and k < size());\n\
    \        return prod(k, k+1);\n    }\n    void apply(int l, int r, F lazy) {\n\
    \        assert(0 <= l and l <= r and r <= size());\n        auto p = split(root,\
    \ l);\n        auto q = split(p.second, r-l);\n        root = merge(p.first, merge(set_lazy(q.first,\
    \ lazy), q.second));\n    }\n    node* root;\n\nprotected:\n\n    std::vector<node>\
    \ pool;\n    std::vector<node*> stock;\n    int head = POOL;\n\n    template<typename...\
    \ U>\n    node* alloc(U... args) {\n        return &(*stock[--head] = node(args...));\n\
    \    }\n    void del(node* p) {\n        stock[head++] = p;\n    }\n    void clear()\
    \ {\n        head = POOL;\n        for (int i = 0; i < POOL; ++i) stock[i] = &pool[i];\n\
    \    }\n\n    node* set_lazy(node* p, const F& lazy) {\n        p->prd = mapping(lazy,\
    \ p->prd);\n        if (p->l) p->lazy = composition(p->lazy, lazy);\n        return\
    \ p;\n    }\n\n    node* push(node *p) {\n        if (p->lazy == id()) return\
    \ p;\n        p->l = set_lazy(p->l, p->lazy);\n        p->r = set_lazy(p->r, p->lazy);\n\
    \        p->lazy = id();\n        return p;\n    }\n\n    node* build(const std::vector<S>&\
    \ v, int l, int r) {\n        if (r - l == 1) return alloc(v[l]);\n        return\
    \ merge(build(v, l, (l+r)/2), build(v, (l+r)/2, r));\n    }\n\n    node* merge_sub(node\
    \ *a, node *b) {\n        if (a->rnk < b->rnk) {\n            b = push(b);\n \
    \           auto c = merge_sub(a, b->l);\n            node *ret;\n           \
    \ if (b->color and !c->color and !c->l->color) {\n                if (b->r->color)\
    \ ret = alloc(c->l, alloc(c->r, b->r, R), B), del(c);\n                else ret\
    \ = alloc(as_root(c), as_root(b->r), R);\n            } else {\n             \
    \   ret = alloc(c, b->r, b->color);\n            }\n            del(b); return\
    \ ret;\n        } else if (a->rnk > b->rnk) {\n            a = push(a);\n    \
    \        auto c = merge_sub(a->r, b);\n            node *ret;\n            if\
    \ (a->color and !c->color and !c->r->color) {\n                if (a->l->color)\
    \ ret = alloc(alloc(a->l, c->l, R), c->r, B), del(c);\n                else ret\
    \ = alloc(as_root(a->l), as_root(c), R);\n            } else {\n             \
    \   ret = alloc(a->l, c, a->color);\n            }\n            del(a); return\
    \ ret;\n        } else {\n            return alloc(a, b, R);\n        }\n    }\n\
    \n    node* as_root(node *p) {\n        if (!p or p->color) return p;\n      \
    \  p->color = B;\n        return p;\n    }\n\n    S prod(node *p, int a, int b,\
    \ F lazy, int l, int r) {\n        if (b <= l or r <= a) return e();\n       \
    \ if (l <= a and b <= r) return mapping(lazy, p->prd);\n        return op(prod(p->l,\
    \ a, a + p->l->sz, composition(p->lazy, lazy), l, r),\n                  prod(p->r,\
    \ b - p->r->sz, b, composition(p->lazy, lazy), l, r));\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_REDBLACKLAZYSEGTREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/redblacklazysegtree.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/redblacklazysegtree.test.cpp
documentation_of: atcoder/redblacklazysegtree.hpp
layout: document
redirect_from:
- /library/atcoder/redblacklazysegtree.hpp
- /library/atcoder/redblacklazysegtree.hpp.html
title: atcoder/redblacklazysegtree.hpp
---
