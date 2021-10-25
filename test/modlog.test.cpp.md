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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/modlog.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <atcoder/math_enhanced>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int t; cin >> t;\n    while (t--) {\n\
    \        int x, y, m; cin >> x >> y >> m;\n        cout << mod_log(x, y, m) <<\
    \ endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <atcoder/math_enhanced>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint main() {\n    int t; cin >> t;\n    while (t--) {\n\
    \        int x, y, m; cin >> x >> y >> m;\n        cout << mod_log(x, y, m) <<\
    \ endl;\n    }\n}\n"
  dependsOn:
  - atcoder/math_enhanced.hpp
  isVerificationFile: true
  path: test/modlog.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 14:39:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modlog.test.cpp
layout: document
redirect_from:
- /verify/test/modlog.test.cpp
- /verify/test/modlog.test.cpp.html
title: test/modlog.test.cpp
---
