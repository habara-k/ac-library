---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bitwise_and_convolution.test.cpp
    title: test/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bitwise_or_convolution.test.cpp
    title: test/bitwise_or_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/xor_convolution.test.cpp
    title: test/xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/kronecker_power_transform.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <functional>\n\nnamespace atcoder {\n\ntemplate<class T,\
    \ void (*f)(T&, T&)>\nvoid kronecker_power_transform(std::vector<T>& a) {\n  \
    \  int n = int(a.size());\n    assert((n & (n-1)) == 0);\n    for (int block =\
    \ 1; block < n; block *= 2) {\n        for (int l = 0; l < n; l += 2 * block)\
    \ {\n            for (int i = l; i < l + block; i++) {\n                f(a[i],\
    \ a[i+block]);\n            }\n        }\n    }\n}\n\ntemplate<class T> struct\
    \ SupersetZetaTransform {\n    static inline void unit(T& x, T& y) { x += y; }\n\
    \    static void apply(std::vector<T>& a) {\n        // a'[s] = \\sum_{s \\subset\
    \ t} a[t]\n        kronecker_power_transform<T,unit>(a);\n    }\n};\n\ntemplate<class\
    \ T> struct SubsetZetaTransform {\n    static inline void unit(T& x, T& y) { y\
    \ += x; }\n    static void apply(std::vector<T>& a) {\n        // a'[s] = \\sum_{t\
    \ \\subset s} a[t]\n        kronecker_power_transform<T,unit>(a);\n    }\n};\n\
    \ntemplate<class T> struct SupersetMobiusTransform {\n    static inline void unit(T&\
    \ x, T& y) { x -= y; }\n    static void apply(std::vector<T>& a) {\n        //\
    \ a[s] = \\sum_{s \\subset t} a'[t]\n        kronecker_power_transform<T,unit>(a);\n\
    \    }\n};\n\ntemplate<class T> struct SubsetMobiusTransform {\n    static inline\
    \ void unit(T& x, T& y) { y -= x; }\n    static void apply(std::vector<T>& a)\
    \ {\n        // a[s] = \\sum_{t \\subset s} a'[t]\n        kronecker_power_transform<T,unit>(a);\n\
    \    }\n};\n\ntemplate<class T> struct HadamardTransform {\n    static inline\
    \ void f(T& x, T& y) { T t = x + y; y = x - y; x = t; }\n    static void apply(std::vector<T>&\
    \ a, bool inv = false) {\n        kronecker_power_transform<T,f>(a);\n       \
    \ if (inv) {\n            for (auto &e : a) e /= a.size();\n        }\n    }\n\
    };\n\ntemplate<class T>\nvoid xor_convolution(std::vector<T>& a, std::vector<T>&\
    \ b) {\n    // a'[k] = \\sum_{i xor j = k} a[i]b[j]\n    // b' = undefined\n \
    \   assert(a.size() == b.size());\n    HadamardTransform<T>::apply(a);\n    HadamardTransform<T>::apply(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];\n    HadamardTransform<T>::apply(a,\
    \ true);\n}\n\ntemplate<class T>\nvoid bitwise_and_convolution(std::vector<T>&\
    \ a, std::vector<T>& b) {\n    // a'[k] = \\sum_{i and j = k} a[i]b[j]\n    //\
    \ b' = undefined\n    assert(a.size() == b.size());\n    SupersetZetaTransform<T>::apply(a);\n\
    \    SupersetZetaTransform<T>::apply(b);\n    for (int i = 0; i < int(a.size());\
    \ i++) a[i] *= b[i];\n    SupersetMobiusTransform<T>::apply(a);\n}\n\ntemplate<class\
    \ T>\nvoid bitwise_or_convolution(std::vector<T>& a, std::vector<T>& b) {\n  \
    \  // a'[k] = \\sum_{i or j = k} a[i]b[j]\n    // b' = undefined\n    assert(a.size()\
    \ == b.size());\n    SubsetZetaTransform<T>::apply(a);\n    SubsetZetaTransform<T>::apply(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];\n    SubsetMobiusTransform<T>::apply(a);\n\
    }\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_KRONECKER_POWER_TRANSFORM_HPP\n#define ATCODER_KRONECKER_POWER_TRANSFORM_HPP\
    \ 1\n\n#include <vector>\n#include <functional>\n\nnamespace atcoder {\n\ntemplate<class\
    \ T, void (*f)(T&, T&)>\nvoid kronecker_power_transform(std::vector<T>& a) {\n\
    \    int n = int(a.size());\n    assert((n & (n-1)) == 0);\n    for (int block\
    \ = 1; block < n; block *= 2) {\n        for (int l = 0; l < n; l += 2 * block)\
    \ {\n            for (int i = l; i < l + block; i++) {\n                f(a[i],\
    \ a[i+block]);\n            }\n        }\n    }\n}\n\ntemplate<class T> struct\
    \ SupersetZetaTransform {\n    static inline void unit(T& x, T& y) { x += y; }\n\
    \    static void apply(std::vector<T>& a) {\n        // a'[s] = \\sum_{s \\subset\
    \ t} a[t]\n        kronecker_power_transform<T,unit>(a);\n    }\n};\n\ntemplate<class\
    \ T> struct SubsetZetaTransform {\n    static inline void unit(T& x, T& y) { y\
    \ += x; }\n    static void apply(std::vector<T>& a) {\n        // a'[s] = \\sum_{t\
    \ \\subset s} a[t]\n        kronecker_power_transform<T,unit>(a);\n    }\n};\n\
    \ntemplate<class T> struct SupersetMobiusTransform {\n    static inline void unit(T&\
    \ x, T& y) { x -= y; }\n    static void apply(std::vector<T>& a) {\n        //\
    \ a[s] = \\sum_{s \\subset t} a'[t]\n        kronecker_power_transform<T,unit>(a);\n\
    \    }\n};\n\ntemplate<class T> struct SubsetMobiusTransform {\n    static inline\
    \ void unit(T& x, T& y) { y -= x; }\n    static void apply(std::vector<T>& a)\
    \ {\n        // a[s] = \\sum_{t \\subset s} a'[t]\n        kronecker_power_transform<T,unit>(a);\n\
    \    }\n};\n\ntemplate<class T> struct HadamardTransform {\n    static inline\
    \ void f(T& x, T& y) { T t = x + y; y = x - y; x = t; }\n    static void apply(std::vector<T>&\
    \ a, bool inv = false) {\n        kronecker_power_transform<T,f>(a);\n       \
    \ if (inv) {\n            for (auto &e : a) e /= a.size();\n        }\n    }\n\
    };\n\ntemplate<class T>\nvoid xor_convolution(std::vector<T>& a, std::vector<T>&\
    \ b) {\n    // a'[k] = \\sum_{i xor j = k} a[i]b[j]\n    // b' = undefined\n \
    \   assert(a.size() == b.size());\n    HadamardTransform<T>::apply(a);\n    HadamardTransform<T>::apply(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];\n    HadamardTransform<T>::apply(a,\
    \ true);\n}\n\ntemplate<class T>\nvoid bitwise_and_convolution(std::vector<T>&\
    \ a, std::vector<T>& b) {\n    // a'[k] = \\sum_{i and j = k} a[i]b[j]\n    //\
    \ b' = undefined\n    assert(a.size() == b.size());\n    SupersetZetaTransform<T>::apply(a);\n\
    \    SupersetZetaTransform<T>::apply(b);\n    for (int i = 0; i < int(a.size());\
    \ i++) a[i] *= b[i];\n    SupersetMobiusTransform<T>::apply(a);\n}\n\ntemplate<class\
    \ T>\nvoid bitwise_or_convolution(std::vector<T>& a, std::vector<T>& b) {\n  \
    \  // a'[k] = \\sum_{i or j = k} a[i]b[j]\n    // b' = undefined\n    assert(a.size()\
    \ == b.size());\n    SubsetZetaTransform<T>::apply(a);\n    SubsetZetaTransform<T>::apply(b);\n\
    \    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];\n    SubsetMobiusTransform<T>::apply(a);\n\
    }\n\n}  // namespace atcoder\n\n#endif  // ATCODER_KRONECKER_POWER_TRANSFORM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/kronecker_power_transform.hpp
  requiredBy: []
  timestamp: '2021-10-21 01:48:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/xor_convolution.test.cpp
  - test/bitwise_and_convolution.test.cpp
  - test/bitwise_or_convolution.test.cpp
documentation_of: atcoder/kronecker_power_transform.hpp
layout: document
redirect_from:
- /library/atcoder/kronecker_power_transform.hpp
- /library/atcoder/kronecker_power_transform.hpp.html
title: atcoder/kronecker_power_transform.hpp
---
