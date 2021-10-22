---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rollinghash.test.cpp
    title: test/rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/rollinghash.hpp\"\n\n\n\n#include <random>\n\nnamespace\
    \ atcoder {\n\nstruct RollingHash {\n    using u128 = __uint128_t;\n    using\
    \ u64 = uint64_t;\n\n    template<typename S>\n    explicit RollingHash(const\
    \ S &s, int seed=0) {\n        std::mt19937 random(seed);\n        std::uniform_int_distribution<u64>\
    \ dist(2, MOD-2);\n        u64 base = dist(random);\n        int n = int(s.size());\n\
    \        hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n        for (int i\
    \ = 0; i < n; ++i) {\n            hash[i+1] = mul(hash[i], base) + s[i];\n   \
    \         if (hash[i+1] >= MOD) hash[i+1] -= MOD;\n            pow[i+1] = mul(pow[i],\
    \ base);\n        }\n    }\n\n    u64 get(int l, int r) const {\n        u64 ret\
    \ = hash[r] + MOD - mul(hash[l], pow[r-l]);\n        return ret >= MOD ? ret -\
    \ MOD : ret;\n    }\n\nprivate:\n    std::vector<u64> hash, pow;\n\n    static\
    \ const u64 MOD = (1ull << 61) - 1;\n\n    static u64 mul(u128 a, u128 b) {\n\
    \        u128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        return u64(t\
    \ >= MOD ? t - MOD : t);\n    }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_ROLLINGHASH_HPP\n#define ATCODER_ROLLINGHASH_HPP 1\n\n#include\
    \ <random>\n\nnamespace atcoder {\n\nstruct RollingHash {\n    using u128 = __uint128_t;\n\
    \    using u64 = uint64_t;\n\n    template<typename S>\n    explicit RollingHash(const\
    \ S &s, int seed=0) {\n        std::mt19937 random(seed);\n        std::uniform_int_distribution<u64>\
    \ dist(2, MOD-2);\n        u64 base = dist(random);\n        int n = int(s.size());\n\
    \        hash.assign(n+1, 0);\n        pow.assign(n+1, 1);\n        for (int i\
    \ = 0; i < n; ++i) {\n            hash[i+1] = mul(hash[i], base) + s[i];\n   \
    \         if (hash[i+1] >= MOD) hash[i+1] -= MOD;\n            pow[i+1] = mul(pow[i],\
    \ base);\n        }\n    }\n\n    u64 get(int l, int r) const {\n        u64 ret\
    \ = hash[r] + MOD - mul(hash[l], pow[r-l]);\n        return ret >= MOD ? ret -\
    \ MOD : ret;\n    }\n\nprivate:\n    std::vector<u64> hash, pow;\n\n    static\
    \ const u64 MOD = (1ull << 61) - 1;\n\n    static u64 mul(u128 a, u128 b) {\n\
    \        u128 t = a * b;\n        t = (t >> 61) + (t & MOD);\n        return u64(t\
    \ >= MOD ? t - MOD : t);\n    }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_ROLLINGHASH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/rollinghash.hpp
  requiredBy: []
  timestamp: '2021-10-21 20:15:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rollinghash.test.cpp
documentation_of: atcoder/rollinghash.hpp
layout: document
redirect_from:
- /library/atcoder/rollinghash.hpp
- /library/atcoder/rollinghash.hpp.html
title: atcoder/rollinghash.hpp
---
