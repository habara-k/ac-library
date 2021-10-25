---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
  bundledCode: "#line 1 \"test/combination.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
    \n\n#include <atcoder/combination>\n#include <atcoder/modint>\n#include <iostream>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nint main() {\n    int n, k;\n\
    \    cin >> n >> k;\n\n    if (n > k) {\n        cout << 0 << endl;\n        return\
    \ 0;\n    }\n\n    using Int = modint1000000007;\n    Combination<Int> comb(k);\n\
    \n    cout << (comb.C(k, n) * comb.fact(n)).val() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
    \n\n#include <atcoder/combination>\n#include <atcoder/modint>\n#include <iostream>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nint main() {\n    int n, k;\n\
    \    cin >> n >> k;\n\n    if (n > k) {\n        cout << 0 << endl;\n        return\
    \ 0;\n    }\n\n    using Int = modint1000000007;\n    Combination<Int> comb(k);\n\
    \n    cout << (comb.C(k, n) * comb.fact(n)).val() << endl;\n}\n"
  dependsOn:
  - atcoder/combination.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: true
  path: test/combination.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/combination.test.cpp
layout: document
redirect_from:
- /verify/test/combination.test.cpp
- /verify/test/combination.test.cpp.html
title: test/combination.test.cpp
---
