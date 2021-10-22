---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/centroid.hpp
    title: atcoder/centroid.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/treehash.hpp
    title: atcoder/treehash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
  bundledCode: "#line 1 \"test/treehash.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n\n#include <atcoder/treehash>\n#include <atcoder/dsu>\n#include <iostream>\n\
    #include <map>\n\nusing namespace atcoder;\nusing namespace std;\n\nint main()\
    \ {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n    dsu\
    \ uf(n1);\n    for (int i = 0; i < m1; i++) {\n        int u, v; cin >> u >> v;\
    \ --u, --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n\
    \        uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>>\
    \ g2(n2);\n    for (int i = 0; i < n2-1; i++) {\n        int u, v; cin >> u >>\
    \ v; --u, --v;\n        g2[u].emplace_back(v);\n        g2[v].emplace_back(u);\n\
    \    }\n\n    vector<int> roots;\n    for (int i = 0; i < n1; ++i) if (uf.leader(i)\
    \ == i) roots.emplace_back(i);\n\n    map<int,map<int,int>> ord;\n    for (int\
    \ i = 0; i < n1; ++i) {\n        ord[uf.leader(i)][i] = -1;\n    }\n\n    map<int,vector<vector<int>>>\
    \ g;\n    for (auto& tp : ord) {\n        int cnt = 0;\n        for (auto& p :\
    \ tp.second) {\n            p.second = cnt++;\n        }\n        g[tp.first].resize(cnt);\n\
    \    }\n\n    for (int u = 0; u < n1; ++u) {\n        int r = uf.leader(u);\n\
    \        for (int v : g1[u]) {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n\
    \        }\n    }\n\n    int ans = 0;\n    auto hash = TreeHash{g2}.get();\n \
    \   for (auto &tp : g) {\n        auto h = TreeHash{tp.second}.get();\n      \
    \  ans += h == hash;\n    }\n\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n\n#include <atcoder/treehash>\n#include <atcoder/dsu>\n#include <iostream>\n\
    #include <map>\n\nusing namespace atcoder;\nusing namespace std;\n\nint main()\
    \ {\n    int n1, m1; cin >> n1 >> m1;\n    vector<vector<int>> g1(n1);\n    dsu\
    \ uf(n1);\n    for (int i = 0; i < m1; i++) {\n        int u, v; cin >> u >> v;\
    \ --u, --v;\n        g1[u].emplace_back(v);\n        g1[v].emplace_back(u);\n\
    \        uf.merge(u, v);\n    }\n    int n2; cin >> n2;\n    vector<vector<int>>\
    \ g2(n2);\n    for (int i = 0; i < n2-1; i++) {\n        int u, v; cin >> u >>\
    \ v; --u, --v;\n        g2[u].emplace_back(v);\n        g2[v].emplace_back(u);\n\
    \    }\n\n    vector<int> roots;\n    for (int i = 0; i < n1; ++i) if (uf.leader(i)\
    \ == i) roots.emplace_back(i);\n\n    map<int,map<int,int>> ord;\n    for (int\
    \ i = 0; i < n1; ++i) {\n        ord[uf.leader(i)][i] = -1;\n    }\n\n    map<int,vector<vector<int>>>\
    \ g;\n    for (auto& tp : ord) {\n        int cnt = 0;\n        for (auto& p :\
    \ tp.second) {\n            p.second = cnt++;\n        }\n        g[tp.first].resize(cnt);\n\
    \    }\n\n    for (int u = 0; u < n1; ++u) {\n        int r = uf.leader(u);\n\
    \        for (int v : g1[u]) {\n            g[r][ord[r][u]].emplace_back(ord[r][v]);\n\
    \        }\n    }\n\n    int ans = 0;\n    auto hash = TreeHash{g2}.get();\n \
    \   for (auto &tp : g) {\n        auto h = TreeHash{tp.second}.get();\n      \
    \  ans += h == hash;\n    }\n\n    cout << ans << endl;\n}\n"
  dependsOn:
  - atcoder/treehash.hpp
  - atcoder/centroid.hpp
  - atcoder/dsu.hpp
  isVerificationFile: true
  path: test/treehash.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/treehash.test.cpp
layout: document
redirect_from:
- /verify/test/treehash.test.cpp
- /verify/test/treehash.test.cpp.html
title: test/treehash.test.cpp
---
