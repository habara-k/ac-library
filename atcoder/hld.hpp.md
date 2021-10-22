---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/hld.test.cpp
    title: test/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/persistentsegtree.test.cpp
    title: test/persistentsegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html
  bundledCode: "#line 1 \"atcoder/hld.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n// Reference: https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html\n\
    \ntemplate< typename G >\nstruct HeavyLightDecomposition {\n    G &g;\n    std::vector<\
    \ int > sz, in, out, head, rev, par;\n\n    explicit HeavyLightDecomposition(G\
    \ &g_) :\n            g(g_), sz(g.size()), in(g.size()), out(g.size()), head(g.size()),\
    \ rev(g.size()), par(g.size()) {\n        build();\n    }\n\n    int la(int v,\
    \ int k) {\n        while(1) {\n            int u = head[v];\n            if(in[v]\
    \ - k >= in[u]) return rev[in[v] - k];\n            k -= in[v] - in[u] + 1;\n\
    \            v = par[u];\n        }\n    }\n\n    int lca(int u, int v) {\n  \
    \      for(;; v = par[head[v]]) {\n            if(in[u] > in[v]) std::swap(u,\
    \ v);\n            if(head[u] == head[v]) return u;\n        }\n    }\n\n    template<\
    \ typename T, typename Q, typename F >\n    T prod(int u, int v, const T &id,\
    \ const Q &q, const F &f, bool edge = false) {\n        // Require: f(a, b) ==\
    \ f(b, a)\n        T s = id;\n        for(;; v = par[head[v]]) {\n           \
    \ if(in[u] > in[v]) std::swap(u, v);\n            if(head[u] == head[v]) break;\n\
    \            s = f(s, q(in[head[v]], in[v] + 1));\n        }\n        return f(s,\
    \ q(in[u] + edge, in[v] + 1));\n    }\n\n    template< typename Q >\n    void\
    \ apply(int u, int v, const Q &q, bool edge = false) {\n        for(;; v = par[head[v]])\
    \ {\n            if(in[u] > in[v]) std::swap(u, v);\n            if(head[u] ==\
    \ head[v]) break;\n            q(in[head[v]], in[v] + 1);\n        }\n       \
    \ q(in[u] + edge, in[v] + 1);\n    }\n\nprivate:\n    void dfs_sz(int idx, int\
    \ p) {\n        par[idx] = p;\n        sz[idx] = 1;\n        if(g[idx].size()\
    \ && g[idx][0] == p) std::swap(g[idx][0], g[idx].back());\n        for(auto &to\
    \ : g[idx]) {\n            if(to == p) continue;\n            dfs_sz(to, idx);\n\
    \            sz[idx] += sz[to];\n            if(sz[g[idx][0]] < sz[to]) std::swap(g[idx][0],\
    \ to);\n        }\n    }\n\n    void dfs_hld(int idx, int p, int &times) {\n \
    \       in[idx] = times++;\n        rev[in[idx]] = idx;\n        for(auto &to\
    \ : g[idx]) {\n            if(to == p) continue;\n            head[to] = (g[idx][0]\
    \ == to ? head[idx] : to);\n            dfs_hld(to, idx, times);\n        }\n\
    \        out[idx] = times;\n    }\n\n    void build() {\n        dfs_sz(0, -1);\n\
    \        int t = 0;\n        dfs_hld(0, -1, t);\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_HLD_HPP\n#define ATCODER_HLD_HPP 1\n\n#include <vector>\n\
    \nnamespace atcoder {\n\n// Reference: https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html\n\
    \ntemplate< typename G >\nstruct HeavyLightDecomposition {\n    G &g;\n    std::vector<\
    \ int > sz, in, out, head, rev, par;\n\n    explicit HeavyLightDecomposition(G\
    \ &g_) :\n            g(g_), sz(g.size()), in(g.size()), out(g.size()), head(g.size()),\
    \ rev(g.size()), par(g.size()) {\n        build();\n    }\n\n    int la(int v,\
    \ int k) {\n        while(1) {\n            int u = head[v];\n            if(in[v]\
    \ - k >= in[u]) return rev[in[v] - k];\n            k -= in[v] - in[u] + 1;\n\
    \            v = par[u];\n        }\n    }\n\n    int lca(int u, int v) {\n  \
    \      for(;; v = par[head[v]]) {\n            if(in[u] > in[v]) std::swap(u,\
    \ v);\n            if(head[u] == head[v]) return u;\n        }\n    }\n\n    template<\
    \ typename T, typename Q, typename F >\n    T prod(int u, int v, const T &id,\
    \ const Q &q, const F &f, bool edge = false) {\n        // Require: f(a, b) ==\
    \ f(b, a)\n        T s = id;\n        for(;; v = par[head[v]]) {\n           \
    \ if(in[u] > in[v]) std::swap(u, v);\n            if(head[u] == head[v]) break;\n\
    \            s = f(s, q(in[head[v]], in[v] + 1));\n        }\n        return f(s,\
    \ q(in[u] + edge, in[v] + 1));\n    }\n\n    template< typename Q >\n    void\
    \ apply(int u, int v, const Q &q, bool edge = false) {\n        for(;; v = par[head[v]])\
    \ {\n            if(in[u] > in[v]) std::swap(u, v);\n            if(head[u] ==\
    \ head[v]) break;\n            q(in[head[v]], in[v] + 1);\n        }\n       \
    \ q(in[u] + edge, in[v] + 1);\n    }\n\nprivate:\n    void dfs_sz(int idx, int\
    \ p) {\n        par[idx] = p;\n        sz[idx] = 1;\n        if(g[idx].size()\
    \ && g[idx][0] == p) std::swap(g[idx][0], g[idx].back());\n        for(auto &to\
    \ : g[idx]) {\n            if(to == p) continue;\n            dfs_sz(to, idx);\n\
    \            sz[idx] += sz[to];\n            if(sz[g[idx][0]] < sz[to]) std::swap(g[idx][0],\
    \ to);\n        }\n    }\n\n    void dfs_hld(int idx, int p, int &times) {\n \
    \       in[idx] = times++;\n        rev[in[idx]] = idx;\n        for(auto &to\
    \ : g[idx]) {\n            if(to == p) continue;\n            head[to] = (g[idx][0]\
    \ == to ? head[idx] : to);\n            dfs_hld(to, idx, times);\n        }\n\
    \        out[idx] = times;\n    }\n\n    void build() {\n        dfs_sz(0, -1);\n\
    \        int t = 0;\n        dfs_hld(0, -1, t);\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_HLD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/hld.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistentsegtree.test.cpp
  - test/hld.test.cpp
documentation_of: atcoder/hld.hpp
layout: document
redirect_from:
- /library/atcoder/hld.hpp
- /library/atcoder/hld.hpp.html
title: atcoder/hld.hpp
---
