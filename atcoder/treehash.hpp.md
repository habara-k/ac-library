---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/centroid.hpp
    title: atcoder/centroid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/treehash.test.cpp
    title: test/treehash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/treehash.hpp\"\n\n\n\n#include <atcoder/centroid>\n\
    #include <algorithm>\n#include <random>\n\nnamespace atcoder {\n\nstruct TreeHash\
    \ {\n    using u128 = __uint128_t;\n    using u64 = uint64_t;\n\n    explicit\
    \ TreeHash(const std::vector<std::vector<int>>& g_, int seed=0) : g(g_) {\n  \
    \      int n = int(g.size());\n        std::mt19937 random(seed);\n        std::uniform_int_distribution<u64>\
    \ dist(2, MOD-2);\n        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));\n\
    \    }\n\n    u64 get() {\n        std::vector<u64> hash;\n        for (int root\
    \ : centroid(g)) {\n            hash.emplace_back(dfs(root, -1, 0));\n       \
    \ }\n        return *min_element(hash.begin(), hash.end());\n    }\n\nprivate:\n\
    \    std::vector<u64> base;\n    std::vector<std::vector<int>> g;\n    static\
    \ const u64 MOD = (1ull << 61) - 1;\n\n    static u64 mul(u128 a, u128 b) {\n\
    \        u128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        return u64(t\
    \ >= MOD ? t - MOD : t);\n    }\n\n    u64 dfs(int u, int p, int d) {\n      \
    \  u64 hash = 1;\n        for (int v : g[u]) {\n            if (v == p) continue;\n\
    \            hash = mul(hash, dfs(v, u, d+1));\n        }\n        hash += base[d];\n\
    \        return hash >= MOD ? hash - MOD : hash;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_TREEHASH_HPP\n#define ATCODER_TREEHASH_HPP 1\n\n#include\
    \ <atcoder/centroid>\n#include <algorithm>\n#include <random>\n\nnamespace atcoder\
    \ {\n\nstruct TreeHash {\n    using u128 = __uint128_t;\n    using u64 = uint64_t;\n\
    \n    explicit TreeHash(const std::vector<std::vector<int>>& g_, int seed=0) :\
    \ g(g_) {\n        int n = int(g.size());\n        std::mt19937 random(seed);\n\
    \        std::uniform_int_distribution<u64> dist(2, MOD-2);\n        for (int\
    \ i = 0; i < n; ++i) base.emplace_back(dist(random));\n    }\n\n    u64 get()\
    \ {\n        std::vector<u64> hash;\n        for (int root : centroid(g)) {\n\
    \            hash.emplace_back(dfs(root, -1, 0));\n        }\n        return *min_element(hash.begin(),\
    \ hash.end());\n    }\n\nprivate:\n    std::vector<u64> base;\n    std::vector<std::vector<int>>\
    \ g;\n    static const u64 MOD = (1ull << 61) - 1;\n\n    static u64 mul(u128\
    \ a, u128 b) {\n        u128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n\
    \        return u64(t >= MOD ? t - MOD : t);\n    }\n\n    u64 dfs(int u, int\
    \ p, int d) {\n        u64 hash = 1;\n        for (int v : g[u]) {\n         \
    \   if (v == p) continue;\n            hash = mul(hash, dfs(v, u, d+1));\n   \
    \     }\n        hash += base[d];\n        return hash >= MOD ? hash - MOD : hash;\n\
    \    }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_TREEHASH_HPP\n"
  dependsOn:
  - atcoder/centroid.hpp
  isVerificationFile: false
  path: atcoder/treehash.hpp
  requiredBy: []
  timestamp: '2021-10-21 20:15:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/treehash.test.cpp
documentation_of: atcoder/treehash.hpp
layout: document
redirect_from:
- /library/atcoder/treehash.hpp
- /library/atcoder/treehash.hpp.html
title: atcoder/treehash.hpp
---
