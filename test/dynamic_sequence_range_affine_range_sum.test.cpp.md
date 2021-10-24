---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/rbtree.hpp
    title: atcoder/rbtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/dynamic_sequence_range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <atcoder/rbtree>\n#include <atcoder/modint>\n#include <iostream>\n\
    #include <limits>\n\nusing namespace atcoder;\nusing namespace std;\n\nusing mint\
    \ = modint998244353;\nstruct node {\n    mint x;\n    int len;\n};\nnode op(node\
    \ a, node b) {\n    return node{a.x + b.x, a.len + b.len};\n}\nnode e() { return\
    \ {0, 0}; }\n\nstruct affine {\n    mint a, b;\n};\nbool operator!=(affine f,\
    \ affine g) {\n    return f.a != g.a or f.b != g.b;\n}\naffine id() { return affine{1,\
    \ 0}; }\nnode mapping(affine f, node t) {\n    return node{f.a * t.x + f.b * t.len,\
    \ t.len};\n}\naffine composition(affine f, affine g) {\n    return affine{f.a\
    \ * g.a, f.b * g.a + g.b};\n}\n\nint main() {\n    int n, q; cin >> n >> q;\n\
    \    vector<node> a(n);\n    for (int i = 0; i < n; i++) {\n        int x; cin\
    \ >> x; a[i].x = x, a[i].len = 1;\n    }\n    rb_lazy_segtree_reversible<node,op,e,affine,mapping,composition,id>\
    \ tree(n+q);\n    tree.build(a);\n    while (q--) {\n        int t; cin >> t;\n\
    \        if (t == 0) {\n            int i, x; cin >> i >> x;\n            tree.insert(i,\
    \ node{x, 1});\n        }\n        if (t == 1) {\n            int i; cin >> i;\n\
    \            tree.erase(i);\n        }\n        if (t == 2) {\n            int\
    \ l, r; cin >> l >> r;\n            tree.reverse(l, r);\n        }\n        if\
    \ (t == 3) {\n            int l, r, b, c; cin >> l >> r >> b >> c;\n         \
    \   tree.apply(l, r, affine{b, c});\n        }\n        if (t == 4) {\n      \
    \      int l, r; cin >> l >> r;\n            cout << tree.prod(l, r).x.val() <<\
    \ endl;\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <atcoder/rbtree>\n#include <atcoder/modint>\n#include <iostream>\n\
    #include <limits>\n\nusing namespace atcoder;\nusing namespace std;\n\nusing mint\
    \ = modint998244353;\nstruct node {\n    mint x;\n    int len;\n};\nnode op(node\
    \ a, node b) {\n    return node{a.x + b.x, a.len + b.len};\n}\nnode e() { return\
    \ {0, 0}; }\n\nstruct affine {\n    mint a, b;\n};\nbool operator!=(affine f,\
    \ affine g) {\n    return f.a != g.a or f.b != g.b;\n}\naffine id() { return affine{1,\
    \ 0}; }\nnode mapping(affine f, node t) {\n    return node{f.a * t.x + f.b * t.len,\
    \ t.len};\n}\naffine composition(affine f, affine g) {\n    return affine{f.a\
    \ * g.a, f.b * g.a + g.b};\n}\n\nint main() {\n    int n, q; cin >> n >> q;\n\
    \    vector<node> a(n);\n    for (int i = 0; i < n; i++) {\n        int x; cin\
    \ >> x; a[i].x = x, a[i].len = 1;\n    }\n    rb_lazy_segtree_reversible<node,op,e,affine,mapping,composition,id>\
    \ tree(n+q);\n    tree.build(a);\n    while (q--) {\n        int t; cin >> t;\n\
    \        if (t == 0) {\n            int i, x; cin >> i >> x;\n            tree.insert(i,\
    \ node{x, 1});\n        }\n        if (t == 1) {\n            int i; cin >> i;\n\
    \            tree.erase(i);\n        }\n        if (t == 2) {\n            int\
    \ l, r; cin >> l >> r;\n            tree.reverse(l, r);\n        }\n        if\
    \ (t == 3) {\n            int l, r, b, c; cin >> l >> r >> b >> c;\n         \
    \   tree.apply(l, r, affine{b, c});\n        }\n        if (t == 4) {\n      \
    \      int l, r; cin >> l >> r;\n            cout << tree.prod(l, r).x.val() <<\
    \ endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - atcoder/rbtree.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: true
  path: test/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 07:59:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/dynamic_sequence_range_affine_range_sum.test.cpp
---
