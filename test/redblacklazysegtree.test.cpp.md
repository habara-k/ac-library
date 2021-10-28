---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/rb_lazysegtree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u8D64\u9ED2\u6728"
  - icon: ':heavy_check_mark:'
    path: atcoder/rbtree_base.hpp
    title: "\u8D64\u9ED2\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"test/redblacklazysegtree.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\n\n#include <atcoder/rb_lazysegtree>\n\
    #include <iostream>\n#include <limits>\n\nusing namespace atcoder;\nusing namespace\
    \ std;\n\nint op(int a, int b) { return min(a,b); }\nint e() { return numeric_limits<int>::max();\
    \ }\nint id() { return numeric_limits<int>::max(); }\nint mapping(int a, int b)\
    \ {\n    if (a==id()) return b;\n    return a;\n}\nint composition(int a, int\
    \ b) {\n    if (a==id()) return b;\n    if (b==id()) return a;\n    return b;\n\
    }\n\nint main() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for\
    \ (int i = 0; i < n; i++) cin >> a[i];\n    rb_lazy_segtree<int,op,e,int,mapping,composition,id>\
    \ tree(n);\n    tree.build(a);\n    while (q--) {\n        int t; cin >> t;\n\
    \        if (t == 0) {\n            int l, r; cin >> l >> r;\n            int\
    \ val = tree.erase(r);\n            tree.insert(l, val);\n        }\n        if\
    \ (t == 1) {\n            int l, r; cin >> l >> r;\n            cout << tree.prod(l,\
    \ r+1) << endl;\n        }\n        if (t == 2) {\n            int pos, val; cin\
    \ >> pos >> val;\n            tree.apply(pos, pos+1, val);\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <atcoder/rb_lazysegtree>\n#include <iostream>\n#include <limits>\n\
    \nusing namespace atcoder;\nusing namespace std;\n\nint op(int a, int b) { return\
    \ min(a,b); }\nint e() { return numeric_limits<int>::max(); }\nint id() { return\
    \ numeric_limits<int>::max(); }\nint mapping(int a, int b) {\n    if (a==id())\
    \ return b;\n    return a;\n}\nint composition(int a, int b) {\n    if (a==id())\
    \ return b;\n    if (b==id()) return a;\n    return b;\n}\n\nint main() {\n  \
    \  int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++) cin >> a[i];\n    rb_lazy_segtree<int,op,e,int,mapping,composition,id>\
    \ tree(n);\n    tree.build(a);\n    while (q--) {\n        int t; cin >> t;\n\
    \        if (t == 0) {\n            int l, r; cin >> l >> r;\n            int\
    \ val = tree.erase(r);\n            tree.insert(l, val);\n        }\n        if\
    \ (t == 1) {\n            int l, r; cin >> l >> r;\n            cout << tree.prod(l,\
    \ r+1) << endl;\n        }\n        if (t == 2) {\n            int pos, val; cin\
    \ >> pos >> val;\n            tree.apply(pos, pos+1, val);\n        }\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - atcoder/rb_lazysegtree.hpp
  - atcoder/rbtree_base.hpp
  isVerificationFile: true
  path: test/redblacklazysegtree.test.cpp
  requiredBy: []
  timestamp: '2021-10-28 14:52:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/redblacklazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/redblacklazysegtree.test.cpp
- /verify/test/redblacklazysegtree.test.cpp.html
title: test/redblacklazysegtree.test.cpp
---
