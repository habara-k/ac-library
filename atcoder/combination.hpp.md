---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/combination.test.cpp
    title: test/combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/luzhiled/snippets/math/combination.html
  bundledCode: "#line 1 \"atcoder/combination.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n// Reference: https://ei1333.github.io/luzhiled/snippets/math/combination.html\n\
    \ntemplate<typename T>\nstruct Combination {\n    std::vector<T> _fact, _rfact,\
    \ _inv;\n\n    explicit Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz\
    \ + 1) {\n        _fact[0] = _rfact[sz] = _inv[0] = 1;\n        for(int i = 1;\
    \ i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n        _rfact[sz] /= _fact[sz];\n\
    \        for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);\n\
    \        for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];\n  \
    \  }\n\n    inline T fact(int k) const { return _fact[k]; }\n\n    inline T rfact(int\
    \ k) const { return _rfact[k]; }\n\n    inline T inv(int k) const { return _inv[k];\
    \ }\n\n    T P(int n, int r) const {\n        if(r < 0 || n < r) return 0;\n \
    \       return fact(n) * rfact(n - r);\n    }\n\n    T C(int p, int q) const {\n\
    \        if(q < 0 || p < q) return 0;\n        return fact(p) * rfact(q) * rfact(p\
    \ - q);\n    }\n\n    T H(int n, int r) const {\n        if(n < 0 || r < 0) return\
    \ (0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_COMBINATION_HPP\n#define ATCODER_COMBINATION_HPP 1\n\n#include\
    \ <vector>\n\nnamespace atcoder {\n\n// Reference: https://ei1333.github.io/luzhiled/snippets/math/combination.html\n\
    \ntemplate<typename T>\nstruct Combination {\n    std::vector<T> _fact, _rfact,\
    \ _inv;\n\n    explicit Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz\
    \ + 1) {\n        _fact[0] = _rfact[sz] = _inv[0] = 1;\n        for(int i = 1;\
    \ i <= sz; i++) _fact[i] = _fact[i - 1] * i;\n        _rfact[sz] /= _fact[sz];\n\
    \        for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);\n\
    \        for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];\n  \
    \  }\n\n    inline T fact(int k) const { return _fact[k]; }\n\n    inline T rfact(int\
    \ k) const { return _rfact[k]; }\n\n    inline T inv(int k) const { return _inv[k];\
    \ }\n\n    T P(int n, int r) const {\n        if(r < 0 || n < r) return 0;\n \
    \       return fact(n) * rfact(n - r);\n    }\n\n    T C(int p, int q) const {\n\
    \        if(q < 0 || p < q) return 0;\n        return fact(p) * rfact(q) * rfact(p\
    \ - q);\n    }\n\n    T H(int n, int r) const {\n        if(n < 0 || r < 0) return\
    \ (0);\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_COMBINATION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/combination.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/combination.test.cpp
documentation_of: atcoder/combination.hpp
layout: document
redirect_from:
- /library/atcoder/combination.hpp
- /library/atcoder/combination.hpp.html
title: atcoder/combination.hpp
---
