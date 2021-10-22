---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/rerooting.hpp
    title: atcoder/rerooting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595
  bundledCode: "#line 1 \"test/rerooting.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
    \n\n#include <atcoder/rerooting>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint merge(int a, int b) { return max(a, b); }\nint id()\
    \ { return 0; }\nint mapping(int a, int d) { return a + d; }\n\nint main() {\n\
    \    int n; cin >> n;\n\n    re_rooting<int,merge,id,int,mapping> tree(n);\n \
    \   for (int i = 0; i < n-1; i++) {\n        int u, v; cin >> u >> v; --u, --v;\n\
    \        tree.add_edge(u, v, 1);\n    }\n\n    for (auto a : tree.solve()) {\n\
    \        cout << (n-1) * 2 - a << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
    \n\n#include <atcoder/rerooting>\n#include <iostream>\n\nusing namespace atcoder;\n\
    using namespace std;\n\nint merge(int a, int b) { return max(a, b); }\nint id()\
    \ { return 0; }\nint mapping(int a, int d) { return a + d; }\n\nint main() {\n\
    \    int n; cin >> n;\n\n    re_rooting<int,merge,id,int,mapping> tree(n);\n \
    \   for (int i = 0; i < n-1; i++) {\n        int u, v; cin >> u >> v; --u, --v;\n\
    \        tree.add_edge(u, v, 1);\n    }\n\n    for (auto a : tree.solve()) {\n\
    \        cout << (n-1) * 2 - a << endl;\n    }\n}\n"
  dependsOn:
  - atcoder/rerooting.hpp
  isVerificationFile: true
  path: test/rerooting.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/rerooting.test.cpp
- /verify/test/rerooting.test.cpp.html
title: test/rerooting.test.cpp
---
