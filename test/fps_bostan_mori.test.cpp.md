---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/fps_bostan_mori.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <atcoder/fps>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int d; long long k;\n    cin >> d >>\
    \ k;\n    fps a(d), c(d+1);\n    for (int i = 0; i < d; i++) { int t; cin >> t;\
    \ a[i] = t; }\n    for (int i = 0; i < d; i++) { int t; cin >> t; c[i+1] = -t;\
    \ }\n    c[0] = 1;\n    a = convolution(a, c);\n    a.resize(d);\n\n    cout <<\
    \ bostan_mori(a, c, k).val() << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <atcoder/fps>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int d; long long k;\n    cin >> d >>\
    \ k;\n    fps a(d), c(d+1);\n    for (int i = 0; i < d; i++) { int t; cin >> t;\
    \ a[i] = t; }\n    for (int i = 0; i < d; i++) { int t; cin >> t; c[i+1] = -t;\
    \ }\n    c[0] = 1;\n    a = convolution(a, c);\n    a.resize(d);\n\n    cout <<\
    \ bostan_mori(a, c, k).val() << endl;\n}\n"
  dependsOn:
  - atcoder/fps.hpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: true
  path: test/fps_bostan_mori.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 13:43:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fps_bostan_mori.test.cpp
layout: document
redirect_from:
- /verify/test/fps_bostan_mori.test.cpp
- /verify/test/fps_bostan_mori.test.cpp.html
title: test/fps_bostan_mori.test.cpp
---
