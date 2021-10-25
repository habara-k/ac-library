---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/math_enhanced.hpp
    title: Math Enhanced
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/extgcd.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <atcoder/math_enhanced>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int a, b; cin >> a >> b;\n    int x,\
    \ y;\n    extgcd(a, b, x, y);\n    cout << x << ' ' << y << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <atcoder/math_enhanced>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int a, b; cin >> a >> b;\n    int x,\
    \ y;\n    extgcd(a, b, x, y);\n    cout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - atcoder/math_enhanced.hpp
  isVerificationFile: true
  path: test/extgcd.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 14:39:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/extgcd.test.cpp
layout: document
redirect_from:
- /verify/test/extgcd.test.cpp
- /verify/test/extgcd.test.cpp.html
title: test/extgcd.test.cpp
---
