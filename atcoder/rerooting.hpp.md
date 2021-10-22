---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rerooting.test.cpp
    title: test/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/rerooting.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace atcoder {\n\ntemplate<\n        class T,\n        T\
    \ (*merge)(T,T),\n        T (*id)(),\n        class EdgeData,\n        T (*mapping)(T,EdgeData)>\n\
    struct re_rooting {\n\n    explicit re_rooting(int n) : re_rooting(std::vector<T>(n,\
    \ id())) {}\n    explicit re_rooting(const std::vector<T>& init) : g(init.size()),\
    \ dp(init) {}\n\n    void add_edge(int u, int v, EdgeData d) {\n        add_edge(u,\
    \ v, d, d);\n    }\n    void add_edge(int u, int v, EdgeData d, EdgeData e) {\n\
    \        g[u].push_back((edge){v, d});\n        g[v].push_back((edge){u, e});\n\
    \    }\n\n    // for all root in V:\n    //   sub[u] := merge({ mapping(dp[e.to],\
    \ e.data) | e in rooted_tree[root][u] })\n    //   dp[root] := sub[root]\n   \
    \ std::vector<T> solve() {\n        dfs_sub(0, -1);\n        dfs_all(0, -1, id());\n\
    \        return dp;\n    }\n\nprivate:\n    struct edge {\n        int to;\n \
    \       EdgeData data;\n        T lsum = id(), sub = id();\n    };\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<T> dp;\n\n    T dfs_sub(int u, int par) {\n        for (edge&\
    \ e : g[u]) {\n            if (e.to == par) continue;\n            dp[u] = merge(dp[u],\
    \ mapping(dfs_sub(e.to, u), e.data));\n        }\n        return dp[u];\n    }\n\
    \n    void dfs_all(int u, int par, T top) {\n        dp[u] = id();\n        for\
    \ (edge& e : g[u]) {\n            e.lsum = dp[u];\n            e.sub = mapping(e.to\
    \ == par ? top : dp[e.to], e.data);\n            dp[u] = merge(dp[u], e.sub);\n\
    \        }\n\n        T rsum = id();\n        reverse(g[u].begin(), g[u].end());\n\
    \        for (edge& e : g[u]) {\n            if (e.to != par) dfs_all(e.to, u,\
    \ merge(e.lsum, rsum));\n            rsum = merge(rsum, e.sub);\n        }\n \
    \   }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_REROOTING_HPP\n#define ATCODER_REROOTING_HPP 1\n\n#include\
    \ <vector>\n#include <algorithm>\n\nnamespace atcoder {\n\ntemplate<\n       \
    \ class T,\n        T (*merge)(T,T),\n        T (*id)(),\n        class EdgeData,\n\
    \        T (*mapping)(T,EdgeData)>\nstruct re_rooting {\n\n    explicit re_rooting(int\
    \ n) : re_rooting(std::vector<T>(n, id())) {}\n    explicit re_rooting(const std::vector<T>&\
    \ init) : g(init.size()), dp(init) {}\n\n    void add_edge(int u, int v, EdgeData\
    \ d) {\n        add_edge(u, v, d, d);\n    }\n    void add_edge(int u, int v,\
    \ EdgeData d, EdgeData e) {\n        g[u].push_back((edge){v, d});\n        g[v].push_back((edge){u,\
    \ e});\n    }\n\n    // for all root in V:\n    //   sub[u] := merge({ mapping(dp[e.to],\
    \ e.data) | e in rooted_tree[root][u] })\n    //   dp[root] := sub[root]\n   \
    \ std::vector<T> solve() {\n        dfs_sub(0, -1);\n        dfs_all(0, -1, id());\n\
    \        return dp;\n    }\n\nprivate:\n    struct edge {\n        int to;\n \
    \       EdgeData data;\n        T lsum = id(), sub = id();\n    };\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<T> dp;\n\n    T dfs_sub(int u, int par) {\n        for (edge&\
    \ e : g[u]) {\n            if (e.to == par) continue;\n            dp[u] = merge(dp[u],\
    \ mapping(dfs_sub(e.to, u), e.data));\n        }\n        return dp[u];\n    }\n\
    \n    void dfs_all(int u, int par, T top) {\n        dp[u] = id();\n        for\
    \ (edge& e : g[u]) {\n            e.lsum = dp[u];\n            e.sub = mapping(e.to\
    \ == par ? top : dp[e.to], e.data);\n            dp[u] = merge(dp[u], e.sub);\n\
    \        }\n\n        T rsum = id();\n        reverse(g[u].begin(), g[u].end());\n\
    \        for (edge& e : g[u]) {\n            if (e.to != par) dfs_all(e.to, u,\
    \ merge(e.lsum, rsum));\n            rsum = merge(rsum, e.sub);\n        }\n \
    \   }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_REROOTING_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/rerooting.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rerooting.test.cpp
documentation_of: atcoder/rerooting.hpp
layout: document
redirect_from:
- /library/atcoder/rerooting.hpp
- /library/atcoder/rerooting.hpp.html
title: atcoder/rerooting.hpp
---
