---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/hld.hpp
    title: atcoder/hld.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"test/hld.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include <atcoder/hld>\n#include <atcoder/lazysegtree>\n#include <iostream>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nusing ll = long long;\nstruct\
    \ S {\n    ll sum, len;\n};\nS op(S a, S b) { return S{a.sum + b.sum, a.len +\
    \ b.len}; }\nS e() { return S{0, 0}; }\nS mapping(ll a, S b) { return S{b.sum\
    \ + b.len * a, b.len}; }\nll composition(ll a, ll b) { return a + b; }\nll id()\
    \ { return 0; }\n\nint main()\n{\n    int n; cin >> n;\n    vector<vector<int>>\
    \ G(n);\n    for (int i = 0; i < n; ++i) {\n        int k; cin >> k;\n       \
    \ G[i].resize(k);\n        for (int j = 0; j < k; ++j) {\n            cin >> G[i][j];\n\
    \        }\n    }\n\n    HeavyLightDecomposition hld(G);\n\n    lazy_segtree<S,\
    \ op, e, ll, mapping, composition, id> segt(vector<S>(n, S{0, 1}));\n\n    int\
    \ q; cin >> q;\n    for (int t = 0; t < q; ++t) {\n        int c; cin >> c;\n\
    \        if (c == 0) {\n            int v, w; cin >> v >> w;\n            hld.apply(0,\
    \ v, [&](int l, int r) { segt.apply(l, r, w); }, true);\n        }\n        if\
    \ (c == 1) {\n            int v; cin >> v;\n            cout << hld.prod(0, v,\
    \ e(),\n                      [&](int l, int r) { return segt.prod(l, r); },\n\
    \                      [&](S a, S b) { return op(a, b); }, true).sum << endl;\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include <atcoder/hld>\n#include <atcoder/lazysegtree>\n#include <iostream>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nusing ll = long long;\nstruct\
    \ S {\n    ll sum, len;\n};\nS op(S a, S b) { return S{a.sum + b.sum, a.len +\
    \ b.len}; }\nS e() { return S{0, 0}; }\nS mapping(ll a, S b) { return S{b.sum\
    \ + b.len * a, b.len}; }\nll composition(ll a, ll b) { return a + b; }\nll id()\
    \ { return 0; }\n\nint main()\n{\n    int n; cin >> n;\n    vector<vector<int>>\
    \ G(n);\n    for (int i = 0; i < n; ++i) {\n        int k; cin >> k;\n       \
    \ G[i].resize(k);\n        for (int j = 0; j < k; ++j) {\n            cin >> G[i][j];\n\
    \        }\n    }\n\n    HeavyLightDecomposition hld(G);\n\n    lazy_segtree<S,\
    \ op, e, ll, mapping, composition, id> segt(vector<S>(n, S{0, 1}));\n\n    int\
    \ q; cin >> q;\n    for (int t = 0; t < q; ++t) {\n        int c; cin >> c;\n\
    \        if (c == 0) {\n            int v, w; cin >> v >> w;\n            hld.apply(0,\
    \ v, [&](int l, int r) { segt.apply(l, r, w); }, true);\n        }\n        if\
    \ (c == 1) {\n            int v; cin >> v;\n            cout << hld.prod(0, v,\
    \ e(),\n                      [&](int l, int r) { return segt.prod(l, r); },\n\
    \                      [&](S a, S b) { return op(a, b); }, true).sum << endl;\n\
    \        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - atcoder/hld.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: true
  path: test/hld.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/hld.test.cpp
layout: document
redirect_from:
- /verify/test/hld.test.cpp
- /verify/test/hld.test.cpp.html
title: test/hld.test.cpp
---
