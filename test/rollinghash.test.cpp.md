---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/rollinghash.hpp
    title: atcoder/rollinghash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/rollinghash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include <atcoder/rollinghash>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    string T, P;\n    cin >> T >> P;\n \
    \   int n = int(T.size()), m = int(P.size());\n\n    int seed = random_device{}();\n\
    \    RollingHash rht(T, seed);\n    RollingHash rhp(P, seed);\n\n    for (int\
    \ i = 0; i+m <= n; ++i) {\n        if (rht.get(i, i+m) == rhp.get(0, m)) {\n \
    \           cout << i << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include <atcoder/rollinghash>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    string T, P;\n    cin >> T >> P;\n \
    \   int n = int(T.size()), m = int(P.size());\n\n    int seed = random_device{}();\n\
    \    RollingHash rht(T, seed);\n    RollingHash rhp(P, seed);\n\n    for (int\
    \ i = 0; i+m <= n; ++i) {\n        if (rht.get(i, i+m) == rhp.get(0, m)) {\n \
    \           cout << i << endl;\n        }\n    }\n}\n"
  dependsOn:
  - atcoder/rollinghash.hpp
  isVerificationFile: true
  path: test/rollinghash.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/rollinghash.test.cpp
- /verify/test/rollinghash.test.cpp.html
title: test/rollinghash.test.cpp
---
