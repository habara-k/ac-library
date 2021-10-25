---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/bitmatrix.hpp
    title: atcoder/bitmatrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
  bundledCode: "#line 1 \"test/bitmatrix.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\
    \n\n#include <atcoder/bitmatrix>\n#include <vector>\n#include <iostream>\n\nusing\
    \ namespace atcoder;\nusing namespace std;\n\nint main() {\n    while (true) {\n\
    \        int m, n, d; cin >> m >> n >> d;\n        if (m == 0) break;\n\n    \
    \    BitMatrix<625,625> A(n*m, n*m);\n        for (int i1 = 0; i1 < n; i1++) {\n\
    \            for (int j1 = 0; j1 < m; j1++) {\n                A[i1*m + j1][i1*m\
    \ + j1] = 1;\n                for (int i2 = 0; i2 < n; i2++) {\n             \
    \       for (int j2 = 0; j2 < m; j2++) {\n                        if (abs(i1 -\
    \ i2) + abs(j1 - j2) == d) {\n                            A[i1*m + j1][i2*m +\
    \ j2] = 1;\n                        }\n                    }\n               \
    \ }\n            }\n        }\n        vector<bool> b(n*m), x;\n        for (int\
    \ i = 0; i < n*m; i++) {\n            int f; cin >> f; b[i] = f;\n        }\n\n\
    \        int rank = linear_equation(A, b, x);\n        cout << (rank != -1) <<\
    \ endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\
    \n\n#include <atcoder/bitmatrix>\n#include <vector>\n#include <iostream>\n\nusing\
    \ namespace atcoder;\nusing namespace std;\n\nint main() {\n    while (true) {\n\
    \        int m, n, d; cin >> m >> n >> d;\n        if (m == 0) break;\n\n    \
    \    BitMatrix<625,625> A(n*m, n*m);\n        for (int i1 = 0; i1 < n; i1++) {\n\
    \            for (int j1 = 0; j1 < m; j1++) {\n                A[i1*m + j1][i1*m\
    \ + j1] = 1;\n                for (int i2 = 0; i2 < n; i2++) {\n             \
    \       for (int j2 = 0; j2 < m; j2++) {\n                        if (abs(i1 -\
    \ i2) + abs(j1 - j2) == d) {\n                            A[i1*m + j1][i2*m +\
    \ j2] = 1;\n                        }\n                    }\n               \
    \ }\n            }\n        }\n        vector<bool> b(n*m), x;\n        for (int\
    \ i = 0; i < n*m; i++) {\n            int f; cin >> f; b[i] = f;\n        }\n\n\
    \        int rank = linear_equation(A, b, x);\n        cout << (rank != -1) <<\
    \ endl;\n    }\n}\n"
  dependsOn:
  - atcoder/bitmatrix.hpp
  isVerificationFile: true
  path: test/bitmatrix.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 10:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bitmatrix.test.cpp
layout: document
redirect_from:
- /verify/test/bitmatrix.test.cpp
- /verify/test/bitmatrix.test.cpp.html
title: test/bitmatrix.test.cpp
---
