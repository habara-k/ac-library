---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/waveletmatrix.test.cpp
    title: test/waveletmatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/wavelet/succinct-indexable-dictionary.cpp
    - https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp
  bundledCode: "#line 1 \"atcoder/waveletmatrix.hpp\"\n\n\n\n#include <cassert>\n\
    #include <tuple>\n#include <vector>\n\nnamespace atcoder {\n\n// Reference: https://ei1333.github.io/library/structure/wavelet/succinct-indexable-dictionary.cpp\n\
    \nstruct SuccinctIndexableDictionary {\n    int length;\n    int blocks;\n   \
    \ std::vector< unsigned > bit, sum;\n\n    SuccinctIndexableDictionary() = default;\n\
    \n    explicit SuccinctIndexableDictionary(int length_) : length(length_), blocks((length\
    \ + 31) >> 5) {\n        bit.assign(blocks, 0U);\n        sum.assign(blocks, 0U);\n\
    \    }\n\n    void set(int k) {\n        bit[k >> 5] |= 1U << (k & 31);\n    }\n\
    \n    void build() {\n        sum[0] = 0U;\n        for(int i = 1; i < blocks;\
    \ i++) {\n            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n\
    \        }\n    }\n\n    bool operator[](int k) {\n        return (bool((bit[k\
    \ >> 5] >> (k & 31)) & 1));\n    }\n\n    int rank(int k) {\n        return int(sum[k\
    \ >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n    }\n\n\
    \    int rank(bool val, int k) {\n        return (val ? rank(k) : k - rank(k));\n\
    \    }\n};\n\n\n// Reference: https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp\n\
    \ntemplate< typename T, int MAXLOG >\nstruct WaveletMatrix {\n    int length;\n\
    \    SuccinctIndexableDictionary matrix[MAXLOG];\n    int mid[MAXLOG];\n\n   \
    \ WaveletMatrix() = default;\n\n    explicit WaveletMatrix(std::vector< T > v)\
    \ : length(int(v.size())) {\n        std::vector< T > l(length), r(length);\n\
    \        for(int level = MAXLOG - 1; level >= 0; level--) {\n            matrix[level]\
    \ = SuccinctIndexableDictionary(length + 1);\n            int left = 0, right\
    \ = 0;\n            for(int i = 0; i < length; i++) {\n                if(((v[i]\
    \ >> level) & 1)) {\n                    matrix[level].set(i);\n             \
    \       r[right++] = v[i];\n                } else {\n                    l[left++]\
    \ = v[i];\n                }\n            }\n            mid[level] = left;\n\
    \            matrix[level].build();\n            v.swap(l);\n            for(int\
    \ i = 0; i < right; i++) {\n                v[left + i] = r[i];\n            }\n\
    \        }\n    }\n\n    std::pair< int, int > succ(bool f, int l, int r, int\
    \ level) {\n        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f,\
    \ r) + mid[level] * f};\n    }\n\n    // v[k]\n    T access(int k) {\n       \
    \ T ret = 0;\n        for(int level = MAXLOG - 1; level >= 0; level--) {\n   \
    \         bool f = matrix[level][k];\n            if(f) ret |= T(1) << level;\n\
    \            k = matrix[level].rank(f, k) + mid[level] * f;\n        }\n     \
    \   return ret;\n    }\n\n    T operator[](const int &k) {\n        return access(k);\n\
    \    }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n    int rank(const T\
    \ &x, int r) {\n        int l = 0;\n        for(int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n            std::tie(l, r) = succ((x >> level) & 1, l, r,\
    \ level);\n        }\n        return r - l;\n    }\n\n    // k-th(0-indexed) smallest\
    \ number in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n        assert(0\
    \ <= k && k < r - l);\n        T ret = 0;\n        for(int level = MAXLOG - 1;\
    \ level >= 0; level--) {\n            int cnt = matrix[level].rank(false, r) -\
    \ matrix[level].rank(false, l);\n            bool f = cnt <= k;\n            if(f)\
    \ {\n                ret |= T(1) << level;\n                k -= cnt;\n      \
    \      }\n            std::tie(l, r) = succ(f, l, r, level);\n        }\n    \
    \    return ret;\n    }\n\n    // k-th(0-indexed) largest number in v[l,r)\n \
    \   T kth_largest(int l, int r, int k) {\n        return kth_smallest(l, r, r\
    \ - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n        int ret = 0;\n        for(int\
    \ level = MAXLOG - 1; level >= 0; level--) {\n            bool f = ((upper >>\
    \ level) & 1);\n            if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n            std::tie(l, r) = succ(f, l, r, level);\n        }\n       \
    \ return ret;\n    }\n\n    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)\n\
    \    int range_freq(int l, int r, T lower, T upper) {\n        return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n\n    // max v[i] s.t. (l <= i\
    \ < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n        int\
    \ cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_WAVELETMATRIX_HPP\n#define ATCODER_WAVELETMATRIX_HPP 1\n\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\nnamespace atcoder {\n\
    \n// Reference: https://ei1333.github.io/library/structure/wavelet/succinct-indexable-dictionary.cpp\n\
    \nstruct SuccinctIndexableDictionary {\n    int length;\n    int blocks;\n   \
    \ std::vector< unsigned > bit, sum;\n\n    SuccinctIndexableDictionary() = default;\n\
    \n    explicit SuccinctIndexableDictionary(int length_) : length(length_), blocks((length\
    \ + 31) >> 5) {\n        bit.assign(blocks, 0U);\n        sum.assign(blocks, 0U);\n\
    \    }\n\n    void set(int k) {\n        bit[k >> 5] |= 1U << (k & 31);\n    }\n\
    \n    void build() {\n        sum[0] = 0U;\n        for(int i = 1; i < blocks;\
    \ i++) {\n            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n\
    \        }\n    }\n\n    bool operator[](int k) {\n        return (bool((bit[k\
    \ >> 5] >> (k & 31)) & 1));\n    }\n\n    int rank(int k) {\n        return int(sum[k\
    \ >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n    }\n\n\
    \    int rank(bool val, int k) {\n        return (val ? rank(k) : k - rank(k));\n\
    \    }\n};\n\n\n// Reference: https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp\n\
    \ntemplate< typename T, int MAXLOG >\nstruct WaveletMatrix {\n    int length;\n\
    \    SuccinctIndexableDictionary matrix[MAXLOG];\n    int mid[MAXLOG];\n\n   \
    \ WaveletMatrix() = default;\n\n    explicit WaveletMatrix(std::vector< T > v)\
    \ : length(int(v.size())) {\n        std::vector< T > l(length), r(length);\n\
    \        for(int level = MAXLOG - 1; level >= 0; level--) {\n            matrix[level]\
    \ = SuccinctIndexableDictionary(length + 1);\n            int left = 0, right\
    \ = 0;\n            for(int i = 0; i < length; i++) {\n                if(((v[i]\
    \ >> level) & 1)) {\n                    matrix[level].set(i);\n             \
    \       r[right++] = v[i];\n                } else {\n                    l[left++]\
    \ = v[i];\n                }\n            }\n            mid[level] = left;\n\
    \            matrix[level].build();\n            v.swap(l);\n            for(int\
    \ i = 0; i < right; i++) {\n                v[left + i] = r[i];\n            }\n\
    \        }\n    }\n\n    std::pair< int, int > succ(bool f, int l, int r, int\
    \ level) {\n        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f,\
    \ r) + mid[level] * f};\n    }\n\n    // v[k]\n    T access(int k) {\n       \
    \ T ret = 0;\n        for(int level = MAXLOG - 1; level >= 0; level--) {\n   \
    \         bool f = matrix[level][k];\n            if(f) ret |= T(1) << level;\n\
    \            k = matrix[level].rank(f, k) + mid[level] * f;\n        }\n     \
    \   return ret;\n    }\n\n    T operator[](const int &k) {\n        return access(k);\n\
    \    }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n    int rank(const T\
    \ &x, int r) {\n        int l = 0;\n        for(int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n            std::tie(l, r) = succ((x >> level) & 1, l, r,\
    \ level);\n        }\n        return r - l;\n    }\n\n    // k-th(0-indexed) smallest\
    \ number in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n        assert(0\
    \ <= k && k < r - l);\n        T ret = 0;\n        for(int level = MAXLOG - 1;\
    \ level >= 0; level--) {\n            int cnt = matrix[level].rank(false, r) -\
    \ matrix[level].rank(false, l);\n            bool f = cnt <= k;\n            if(f)\
    \ {\n                ret |= T(1) << level;\n                k -= cnt;\n      \
    \      }\n            std::tie(l, r) = succ(f, l, r, level);\n        }\n    \
    \    return ret;\n    }\n\n    // k-th(0-indexed) largest number in v[l,r)\n \
    \   T kth_largest(int l, int r, int k) {\n        return kth_smallest(l, r, r\
    \ - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n        int ret = 0;\n        for(int\
    \ level = MAXLOG - 1; level >= 0; level--) {\n            bool f = ((upper >>\
    \ level) & 1);\n            if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n            std::tie(l, r) = succ(f, l, r, level);\n        }\n       \
    \ return ret;\n    }\n\n    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)\n\
    \    int range_freq(int l, int r, T lower, T upper) {\n        return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n\n    // max v[i] s.t. (l <= i\
    \ < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n        int\
    \ cnt = range_freq(l, r, upper);\n        return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n        int cnt = range_freq(l, r,\
    \ lower);\n        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n  \
    \  }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_WAVELETMATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/waveletmatrix.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/waveletmatrix.test.cpp
documentation_of: atcoder/waveletmatrix.hpp
layout: document
redirect_from:
- /library/atcoder/waveletmatrix.hpp
- /library/atcoder/waveletmatrix.hpp.html
title: atcoder/waveletmatrix.hpp
---
