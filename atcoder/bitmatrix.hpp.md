---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bitmatrix.test.cpp
    title: test/bitmatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://drken1215.hatenablog.com/entry/2019/03/20/202800
  bundledCode: "#line 1 \"atcoder/bitmatrix.hpp\"\n\n\n\n#include <bitset>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace atcoder {\n\n// https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    template<int MAX_ROW = 510, int MAX_COL = 510>\nstruct BitMatrix {\n    int H,\
    \ W;\n    std::bitset<MAX_COL> val[MAX_ROW];\n    BitMatrix(int h, int w) : H(h),\
    \ W(w) {}\n    std::bitset<MAX_COL>& operator[](int i) { return val[i]; }\n};\n\
    \ntemplate<int MAX_ROW = 510, int MAX_COL = 510>\nstd::ostream& operator<<(std::ostream&\
    \ os, BitMatrix<MAX_ROW, MAX_COL>& A) {\n    os << std::endl;\n    for (int i\
    \ = 0; i < A.H; ++i) {\n        for (int j = 0; j < A.W; ++j) {\n            os\
    \ << A[i][j] << \", \";\n        }\n        os << std::endl;\n    }\n    return\
    \ os;\n}\n\ntemplate<int MAX_ROW = 510, int MAX_COL = 510>\nint GaussJordan(BitMatrix<MAX_ROW,\
    \ MAX_COL> &A, bool is_extended = false) {\n    int rank = 0;\n    for (int col\
    \ = 0; col < A.W; ++col) {\n        if (is_extended && col == A.W - 1) break;\n\
    \        int pivot = -1;\n        for (int row = rank; row < A.H; ++row) {\n \
    \           if (A[row][col]) {\n                pivot = row;\n               \
    \ break;\n            }\n        }\n        if (pivot == -1) continue;\n     \
    \   swap(A[pivot], A[rank]);\n        for (int row = 0; row < A.H; ++row) {\n\
    \            if (row != rank && A[row][col]) A[row] ^= A[rank];\n        }\n \
    \       ++rank;\n    }\n    return rank;\n}\n\ntemplate<int MAX_ROW = 510, int\
    \ MAX_COL = 510>\nint linear_equation(BitMatrix<MAX_ROW, MAX_COL> A, std::vector<int>\
    \ b, std::vector<int> &res) {\n    int m = A.H, n = A.W;\n    BitMatrix<MAX_ROW,MAX_COL>\
    \ M(m, n + 1);\n    for (int i = 0; i < m; ++i) {\n        for (int j = 0; j <\
    \ n; ++j) M[i][j] = A[i][j];\n        M[i][n] = b[i];\n    }\n    int rank = GaussJordan(M,\
    \ true);\n\n    // check if it has no solution\n    for (int row = rank; row <\
    \ m; ++row) if (M[row][n]) return -1;\n\n    // answer\n    res.assign(n, 0);\n\
    \    for (int row = 0, col = 0; row < rank; ++row) {\n        while (M[row][col]\
    \ == 0) ++col;\n        res[col] = M[row][n];\n    }\n    return rank;\n}\n\n\
    }  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_BITMATRIX_HPP\n#define ATCODER_BITMATRIX_HPP 1\n\n#include\
    \ <bitset>\n#include <iostream>\n#include <vector>\n\nnamespace atcoder {\n\n\
    // https://drken1215.hatenablog.com/entry/2019/03/20/202800\ntemplate<int MAX_ROW\
    \ = 510, int MAX_COL = 510>\nstruct BitMatrix {\n    int H, W;\n    std::bitset<MAX_COL>\
    \ val[MAX_ROW];\n    BitMatrix(int h, int w) : H(h), W(w) {}\n    std::bitset<MAX_COL>&\
    \ operator[](int i) { return val[i]; }\n};\n\ntemplate<int MAX_ROW = 510, int\
    \ MAX_COL = 510>\nstd::ostream& operator<<(std::ostream& os, BitMatrix<MAX_ROW,\
    \ MAX_COL>& A) {\n    os << std::endl;\n    for (int i = 0; i < A.H; ++i) {\n\
    \        for (int j = 0; j < A.W; ++j) {\n            os << A[i][j] << \", \"\
    ;\n        }\n        os << std::endl;\n    }\n    return os;\n}\n\ntemplate<int\
    \ MAX_ROW = 510, int MAX_COL = 510>\nint GaussJordan(BitMatrix<MAX_ROW, MAX_COL>\
    \ &A, bool is_extended = false) {\n    int rank = 0;\n    for (int col = 0; col\
    \ < A.W; ++col) {\n        if (is_extended && col == A.W - 1) break;\n       \
    \ int pivot = -1;\n        for (int row = rank; row < A.H; ++row) {\n        \
    \    if (A[row][col]) {\n                pivot = row;\n                break;\n\
    \            }\n        }\n        if (pivot == -1) continue;\n        swap(A[pivot],\
    \ A[rank]);\n        for (int row = 0; row < A.H; ++row) {\n            if (row\
    \ != rank && A[row][col]) A[row] ^= A[rank];\n        }\n        ++rank;\n   \
    \ }\n    return rank;\n}\n\ntemplate<int MAX_ROW = 510, int MAX_COL = 510>\nint\
    \ linear_equation(BitMatrix<MAX_ROW, MAX_COL> A, std::vector<int> b, std::vector<int>\
    \ &res) {\n    int m = A.H, n = A.W;\n    BitMatrix<MAX_ROW,MAX_COL> M(m, n +\
    \ 1);\n    for (int i = 0; i < m; ++i) {\n        for (int j = 0; j < n; ++j)\
    \ M[i][j] = A[i][j];\n        M[i][n] = b[i];\n    }\n    int rank = GaussJordan(M,\
    \ true);\n\n    // check if it has no solution\n    for (int row = rank; row <\
    \ m; ++row) if (M[row][n]) return -1;\n\n    // answer\n    res.assign(n, 0);\n\
    \    for (int row = 0, col = 0; row < rank; ++row) {\n        while (M[row][col]\
    \ == 0) ++col;\n        res[col] = M[row][n];\n    }\n    return rank;\n}\n\n\
    }  // namespace atcoder\n\n#endif  // ATCODER_BITMATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/bitmatrix.hpp
  requiredBy: []
  timestamp: '2021-10-21 15:48:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bitmatrix.test.cpp
documentation_of: atcoder/bitmatrix.hpp
layout: document
redirect_from:
- /library/atcoder/bitmatrix.hpp
- /library/atcoder/bitmatrix.hpp.html
title: atcoder/bitmatrix.hpp
---
