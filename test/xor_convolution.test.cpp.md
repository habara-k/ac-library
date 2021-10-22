---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/kronecker_power_transform.hpp
    title: atcoder/kronecker_power_transform.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/xor_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <atcoder/modint>\n#include <atcoder/kronecker_power_transform>\n\
    #include <iostream>\n#include <vector>\n\nusing namespace atcoder;\nusing namespace\
    \ std;\n\nint main() {\n    int n; cin >> n;\n    using mint = modint998244353;\n\
    \    std::vector<mint> a(1<<n), b(1<<n);\n    for (int i = 0; i < 1<<n; i++) {\n\
    \        int x; cin >> x; a[i] = x;\n    }\n    for (int i = 0; i < 1<<n; i++)\
    \ {\n        int x; cin >> x; b[i] = x;\n    }\n    xor_convolution(a, b);\n \
    \   for (int i = 0; i < 1<<n; i++) {\n        cout << a[i].val() << ' ';\n   \
    \ }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <atcoder/modint>\n#include <atcoder/kronecker_power_transform>\n\
    #include <iostream>\n#include <vector>\n\nusing namespace atcoder;\nusing namespace\
    \ std;\n\nint main() {\n    int n; cin >> n;\n    using mint = modint998244353;\n\
    \    std::vector<mint> a(1<<n), b(1<<n);\n    for (int i = 0; i < 1<<n; i++) {\n\
    \        int x; cin >> x; a[i] = x;\n    }\n    for (int i = 0; i < 1<<n; i++)\
    \ {\n        int x; cin >> x; b[i] = x;\n    }\n    xor_convolution(a, b);\n \
    \   for (int i = 0; i < 1<<n; i++) {\n        cout << a[i].val() << ' ';\n   \
    \ }\n    cout << '\\n';\n}\n"
  dependsOn:
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/kronecker_power_transform.hpp
  isVerificationFile: true
  path: test/xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/xor_convolution.test.cpp
- /verify/test/xor_convolution.test.cpp.html
title: test/xor_convolution.test.cpp
---
