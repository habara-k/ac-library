---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fps.hpp
    title: atcoder/fps.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"test/fps_pow.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include <atcoder/fps>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main()\n{\n    int n, m; cin >> n >> m;\n    fps a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int x; cin >> x;\n        a[i] = x;\n\
    \    }\n    for (auto x : a.pow_inplace(m)) {\n        cout << x.val() << endl;\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include <atcoder/fps>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main()\n{\n    int n, m; cin >> n >> m;\n    fps a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int x; cin >> x;\n        a[i] = x;\n\
    \    }\n    for (auto x : a.pow_inplace(m)) {\n        cout << x.val() << endl;\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - atcoder/fps.hpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: true
  path: test/fps_pow.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps_pow.test.cpp
layout: document
redirect_from:
- /verify/test/fps_pow.test.cpp
- /verify/test/fps_pow.test.cpp.html
title: test/fps_pow.test.cpp
---
