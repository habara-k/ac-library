---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/waveletmatrix.hpp
    title: atcoder/waveletmatrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
  bundledCode: "#line 1 \"test/waveletmatrix.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n\n#include <atcoder/waveletmatrix>\n#include <iostream>\n#include <vector>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nint main() {\n    int n; cin\
    \ >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) cin >> a[i];\n\
    \n    WaveletMatrix<int, 30> mat(a);\n\n    int q; cin >> q;\n    while (q--)\
    \ {\n        int l, r, d; cin >> l >> r >> d;\n        auto check = [&](int k)\
    \ -> bool {\n            return mat.range_freq(l, r+1, max(d-k, 0), d+k+1) > 0;\n\
    \        };\n        int ok = 1e6, ng = -1;\n        while (abs(ok - ng) > 1)\
    \ {\n            int mid = (ok + ng) / 2;\n            (check(mid) ? ok : ng)\
    \ = mid;\n        }\n        cout << ok << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n\n#include <atcoder/waveletmatrix>\n#include <iostream>\n#include <vector>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nint main() {\n    int n; cin\
    \ >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) cin >> a[i];\n\
    \n    WaveletMatrix<int, 30> mat(a);\n\n    int q; cin >> q;\n    while (q--)\
    \ {\n        int l, r, d; cin >> l >> r >> d;\n        auto check = [&](int k)\
    \ -> bool {\n            return mat.range_freq(l, r+1, max(d-k, 0), d+k+1) > 0;\n\
    \        };\n        int ok = 1e6, ng = -1;\n        while (abs(ok - ng) > 1)\
    \ {\n            int mid = (ok + ng) / 2;\n            (check(mid) ? ok : ng)\
    \ = mid;\n        }\n        cout << ok << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - atcoder/waveletmatrix.hpp
  isVerificationFile: true
  path: test/waveletmatrix.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/waveletmatrix.test.cpp
layout: document
redirect_from:
- /verify/test/waveletmatrix.test.cpp
- /verify/test/waveletmatrix.test.cpp.html
title: test/waveletmatrix.test.cpp
---
