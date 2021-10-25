---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/extgcd.test.cpp
    title: test/extgcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modlog.test.cpp
    title: test/modlog.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/math/combinatorics/mod-log.cpp
  bundledCode: "#line 1 \"atcoder/math_enhanced.hpp\"\n\n\n\n#include<numeric>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    \nnamespace atcoder {\n\n// https://ei1333.github.io/library/math/combinatorics/mod-log.cpp\n\
    int64_t mod_log(int64_t a, int64_t b, int64_t p) {\n    ((a %= p) += p) %= p;\n\
    \    ((b %= p) += p) %= p;\n    int64_t g = 1;\n    for (int64_t i = p; i; i /=\
    \ 2) (g *= a) %= p;\n    g = std::gcd(g, p);\n\n    int64_t t = 1, c = 0;\n  \
    \  for (; t % g; c++) {\n        if (t == b) return c;\n        (t *= a) %= p;\n\
    \    }\n\n    if (b % g) return -1;\n\n    t /= g;\n    b /= g;\n    p /= g;\n\
    \n    int64_t h = 0, gs = 1;\n\n    for (; h * h < p; h++) (gs *= a) %= p;\n \
    \   __gnu_pbds::gp_hash_table<int64_t, int64_t> bs;\n    for (int64_t s = 0, e\
    \ = b; s < h; bs[e] = ++s) {\n        (e *= a) %= p;\n    }\n\n    for (int64_t\
    \ s = 0, e = t; s < p;) {\n        (e *= gs) %= p;\n        s += h;\n        if\
    \ (bs.find(e) != bs.end()) return c + s - bs[e];\n    }\n\n    return -1;\n}\n\
    \ntemplate<class T>\nT extgcd(T a, T b, T &x, T &y) {\n    T d = a;\n    if (b\
    \ != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n  \
    \  } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n}  //\
    \ namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_MATH_ENHANCED_HPP\n#define ATCODER_MATH_ENHANCED_HPP 1\n\n\
    #include<numeric>\n#include<ext/pb_ds/assoc_container.hpp>\n\nnamespace atcoder\
    \ {\n\n// https://ei1333.github.io/library/math/combinatorics/mod-log.cpp\nint64_t\
    \ mod_log(int64_t a, int64_t b, int64_t p) {\n    ((a %= p) += p) %= p;\n    ((b\
    \ %= p) += p) %= p;\n    int64_t g = 1;\n    for (int64_t i = p; i; i /= 2) (g\
    \ *= a) %= p;\n    g = std::gcd(g, p);\n\n    int64_t t = 1, c = 0;\n    for (;\
    \ t % g; c++) {\n        if (t == b) return c;\n        (t *= a) %= p;\n    }\n\
    \n    if (b % g) return -1;\n\n    t /= g;\n    b /= g;\n    p /= g;\n\n    int64_t\
    \ h = 0, gs = 1;\n\n    for (; h * h < p; h++) (gs *= a) %= p;\n    __gnu_pbds::gp_hash_table<int64_t,\
    \ int64_t> bs;\n    for (int64_t s = 0, e = b; s < h; bs[e] = ++s) {\n       \
    \ (e *= a) %= p;\n    }\n\n    for (int64_t s = 0, e = t; s < p;) {\n        (e\
    \ *= gs) %= p;\n        s += h;\n        if (bs.find(e) != bs.end()) return c\
    \ + s - bs[e];\n    }\n\n    return -1;\n}\n\ntemplate<class T>\nT extgcd(T a,\
    \ T b, T &x, T &y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a\
    \ % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n     \
    \   y = 0;\n    }\n    return d;\n}\n\n}  // namespace atcoder\n\n#endif  // ATCODER_MATH_ENHANCED_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/math_enhanced.hpp
  requiredBy: []
  timestamp: '2021-10-25 14:39:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/extgcd.test.cpp
  - test/modlog.test.cpp
documentation_of: atcoder/math_enhanced.hpp
layout: document
title: Math Enhanced
---

## 概要

- `mod_log(a, b, p)` : $a^x \equiv b \bmod p$
を満たす最小の非負整数 $x$ を返す. 
そのような $x$ が存在しない場合は -1 を返す.
- `extgcd(a, b, x, y)` : $ax + by = gcd(x,y)$
を満たす $x, y$ を求め, $gcd(x, y)$ を返す.
 
## 制約

- `mod_log(a, b, p)` : $p$ は正整数.
- `extgcd(a, b, x, y)` : $a, b$ は非負整数.

## 計算量

- `mod_log(a, b, p)` : $O(\sqrt{p})$
- `extgcd(a, b, x, y)` : $O(\log \min(a, b))$


