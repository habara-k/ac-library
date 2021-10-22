---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/hld.hpp
    title: atcoder/hld.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/persistentsegtree.hpp
    title: atcoder/persistentsegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270
  bundledCode: "#line 1 \"test/persistentsegtree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\
    \n\n#include <atcoder/persistentsegtree>\n#include <atcoder/hld>\n#include <iostream>\n\
    #include <vector>\n#include <map>\n\nusing namespace atcoder;\nusing namespace\
    \ std;\n\nint op(int a, int b) { return a + b; }\nint e() { return 0; }\n\nint\
    \ main()\n{\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N);\n    for\
    \ (int i = 0; i < N; ++i) {\n        cin >> x[i];\n    }\n\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n\
    \        --a, --b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n \
    \   }\n\n    // compress\n    map<int,int> comp, comp_inv;\n    for (auto X :\
    \ x) comp[X] = -1;\n    int comp_size = 0;\n    for (auto &p : comp) {\n     \
    \   p.second = comp_size++;\n    }\n    for (auto p : comp) {\n        comp_inv[p.second]\
    \ = p.first;\n    }\n\n    // lca\n    auto hld = HeavyLightDecomposition(G);\n\
    \n    // persistent segtree\n    PersistentSegmentTree<int, op, e> segt(comp_size);\n\
    \n    map<int, PersistentSegmentTree<int, op, e>::Node*> root;\n    vector<int>\
    \ par(N);\n\n    auto dfs = [&](auto self, int u, int p) -> void {\n        par[u]\
    \ = p;\n        root[u] = segt.set(root[p],\n                           comp[x[u]],\
    \ segt.get(root[p], comp[x[u]]) + 1);\n        for (int v : G[u]) {\n        \
    \    if (v != p) self(self, v, u);\n        }\n    };\n\n    root[-1] = segt.build();\n\
    \    dfs(dfs, 0, -1);\n\n    for (int i = 0; i < Q; ++i)\n    {\n        int v,\
    \ w, l; cin >> v >> w >> l; --v, --w;\n\n        // search x s.t. there are more\
    \ than l numbers less than or equal to x\n\n        int u = hld.lca(v, w);\n\n\
    \        auto check = [&](int m) {\n            int nv = segt.prod(root[v], 0,\
    \ m+1),\n                    nw = segt.prod(root[w], 0, m+1),\n              \
    \      nu = segt.prod(root[u], 0, m+1),\n                    np = segt.prod(root[par[u]],\
    \ 0, m+1);\n\n            return nv + nw - nu - np >= l;\n        };\n\n     \
    \   int ng = -1, ok = comp_size - 1;\n        while (abs(ok - ng) > 1) {\n   \
    \         int mid = (ng + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n\
    \        }\n\n        cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270\"\
    \n\n#include <atcoder/persistentsegtree>\n#include <atcoder/hld>\n#include <iostream>\n\
    #include <vector>\n#include <map>\n\nusing namespace atcoder;\nusing namespace\
    \ std;\n\nint op(int a, int b) { return a + b; }\nint e() { return 0; }\n\nint\
    \ main()\n{\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N);\n    for\
    \ (int i = 0; i < N; ++i) {\n        cin >> x[i];\n    }\n\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < N-1; ++i) {\n        int a, b; cin >> a >> b;\n\
    \        --a, --b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n \
    \   }\n\n    // compress\n    map<int,int> comp, comp_inv;\n    for (auto X :\
    \ x) comp[X] = -1;\n    int comp_size = 0;\n    for (auto &p : comp) {\n     \
    \   p.second = comp_size++;\n    }\n    for (auto p : comp) {\n        comp_inv[p.second]\
    \ = p.first;\n    }\n\n    // lca\n    auto hld = HeavyLightDecomposition(G);\n\
    \n    // persistent segtree\n    PersistentSegmentTree<int, op, e> segt(comp_size);\n\
    \n    map<int, PersistentSegmentTree<int, op, e>::Node*> root;\n    vector<int>\
    \ par(N);\n\n    auto dfs = [&](auto self, int u, int p) -> void {\n        par[u]\
    \ = p;\n        root[u] = segt.set(root[p],\n                           comp[x[u]],\
    \ segt.get(root[p], comp[x[u]]) + 1);\n        for (int v : G[u]) {\n        \
    \    if (v != p) self(self, v, u);\n        }\n    };\n\n    root[-1] = segt.build();\n\
    \    dfs(dfs, 0, -1);\n\n    for (int i = 0; i < Q; ++i)\n    {\n        int v,\
    \ w, l; cin >> v >> w >> l; --v, --w;\n\n        // search x s.t. there are more\
    \ than l numbers less than or equal to x\n\n        int u = hld.lca(v, w);\n\n\
    \        auto check = [&](int m) {\n            int nv = segt.prod(root[v], 0,\
    \ m+1),\n                    nw = segt.prod(root[w], 0, m+1),\n              \
    \      nu = segt.prod(root[u], 0, m+1),\n                    np = segt.prod(root[par[u]],\
    \ 0, m+1);\n\n            return nv + nw - nu - np >= l;\n        };\n\n     \
    \   int ng = -1, ok = comp_size - 1;\n        while (abs(ok - ng) > 1) {\n   \
    \         int mid = (ng + ok) / 2;\n            (check(mid) ? ok : ng) = mid;\n\
    \        }\n\n        cout << comp_inv[ok] << endl;\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - atcoder/persistentsegtree.hpp
  - atcoder/hld.hpp
  isVerificationFile: true
  path: test/persistentsegtree.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 20:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/persistentsegtree.test.cpp
layout: document
redirect_from:
- /verify/test/persistentsegtree.test.cpp
- /verify/test/persistentsegtree.test.cpp.html
title: test/persistentsegtree.test.cpp
---
