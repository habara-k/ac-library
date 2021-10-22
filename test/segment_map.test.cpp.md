---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/segment_map.hpp
    title: atcoder/segment_map.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
  bundledCode: "#line 1 \"test/segment_map.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \n\n#include <atcoder/segment_map>\n#include <iostream>\n#include <vector>\n#include\
    \ <tuple>\n#include <algorithm>\n\nusing namespace atcoder;\nusing namespace std;\n\
    \nint main() {\n    int n, m, q; cin >> n >> m >> q;\n\n    vector<int> d(m),\
    \ a(m), b(m);\n    for (int i = 0; i < m; i++) cin >> d[i] >> a[i] >> b[i], --a[i],\
    \ --b[i];\n\n    vector<int> e(q), s(q), t(q);\n    for (int i = 0; i < q; i++)\
    \ cin >> e[i] >> s[i] >> t[i], --s[i], --t[i];\n\n    using T = tuple<int,int,int>;\
    \ // time, type, idx\n    vector<T> events;\n    for (int i = 0; i < m; i++) events.emplace_back(d[i],\
    \ 1, i);\n    for (int i = 0; i < q; i++) events.emplace_back(e[i], 0, i);\n \
    \   sort(events.begin(), events.end());\n\n    SegmentMap mp(false);\n    vector<int>\
    \ ans(q);\n    for (auto [time, type, idx] : events) {\n        if (type == 0)\
    \ {\n            // query\n            ans[idx] = s[idx] > t[idx] or mp.same(s[idx],\
    \ t[idx]);\n        }\n        if (type == 1) {\n            // insert\n     \
    \       mp.insert(a[idx], b[idx]);\n        }\n    }\n\n    for (int i = 0; i\
    \ < q; i++) cout << (ans[i] ? \"Yes\" : \"No\") << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \n\n#include <atcoder/segment_map>\n#include <iostream>\n#include <vector>\n#include\
    \ <tuple>\n#include <algorithm>\n\nusing namespace atcoder;\nusing namespace std;\n\
    \nint main() {\n    int n, m, q; cin >> n >> m >> q;\n\n    vector<int> d(m),\
    \ a(m), b(m);\n    for (int i = 0; i < m; i++) cin >> d[i] >> a[i] >> b[i], --a[i],\
    \ --b[i];\n\n    vector<int> e(q), s(q), t(q);\n    for (int i = 0; i < q; i++)\
    \ cin >> e[i] >> s[i] >> t[i], --s[i], --t[i];\n\n    using T = tuple<int,int,int>;\
    \ // time, type, idx\n    vector<T> events;\n    for (int i = 0; i < m; i++) events.emplace_back(d[i],\
    \ 1, i);\n    for (int i = 0; i < q; i++) events.emplace_back(e[i], 0, i);\n \
    \   sort(events.begin(), events.end());\n\n    SegmentMap mp(false);\n    vector<int>\
    \ ans(q);\n    for (auto [time, type, idx] : events) {\n        if (type == 0)\
    \ {\n            // query\n            ans[idx] = s[idx] > t[idx] or mp.same(s[idx],\
    \ t[idx]);\n        }\n        if (type == 1) {\n            // insert\n     \
    \       mp.insert(a[idx], b[idx]);\n        }\n    }\n\n    for (int i = 0; i\
    \ < q; i++) cout << (ans[i] ? \"Yes\" : \"No\") << '\\n';\n}\n"
  dependsOn:
  - atcoder/segment_map.hpp
  isVerificationFile: true
  path: test/segment_map.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment_map.test.cpp
layout: document
redirect_from:
- /verify/test/segment_map.test.cpp
- /verify/test/segment_map.test.cpp.html
title: test/segment_map.test.cpp
---
