---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: atcoder/treehash.hpp
    title: atcoder/treehash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/treehash.test.cpp
    title: test/treehash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/centroid.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
    \ atcoder {\n\nstd::vector<int> centroid(const std::vector<std::vector<int>>&\
    \ g) {\n    const int n = int(g.size());\n    std::vector<int> sz(n,1), ret;\n\
    \    auto dfs = [&](auto self, int u, int p) -> int {\n        bool isCent = true;\n\
    \        for (int v : g[u]) {\n            if (v == p) continue;\n           \
    \ sz[u] += self(self, v, u);\n            if (sz[v] > n / 2) isCent = false;\n\
    \        }\n        if (n - sz[u] > n / 2) isCent = false;\n        if (isCent)\
    \ ret.emplace_back(u);\n        return sz[u];\n    };\n    dfs(dfs, 0, -1);\n\
    \    return ret;\n}\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_CENTROID_HPP\n#define ATCODER_CENTROID_HPP 1\n\n#include\
    \ <vector>\n\nnamespace atcoder {\n\nstd::vector<int> centroid(const std::vector<std::vector<int>>&\
    \ g) {\n    const int n = int(g.size());\n    std::vector<int> sz(n,1), ret;\n\
    \    auto dfs = [&](auto self, int u, int p) -> int {\n        bool isCent = true;\n\
    \        for (int v : g[u]) {\n            if (v == p) continue;\n           \
    \ sz[u] += self(self, v, u);\n            if (sz[v] > n / 2) isCent = false;\n\
    \        }\n        if (n - sz[u] > n / 2) isCent = false;\n        if (isCent)\
    \ ret.emplace_back(u);\n        return sz[u];\n    };\n    dfs(dfs, 0, -1);\n\
    \    return ret;\n}\n\n}  // namespace atcoder\n\n#endif  // ATCODER_CENTROID_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/centroid.hpp
  requiredBy:
  - atcoder/treehash.hpp
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/treehash.test.cpp
documentation_of: atcoder/centroid.hpp
layout: document
redirect_from:
- /library/atcoder/centroid.hpp
- /library/atcoder/centroid.hpp.html
title: atcoder/centroid.hpp
---
