#ifndef ATCODER_BITMATRIX_HPP
#define ATCODER_BITMATRIX_HPP 1

#include <bitset>
#include <iostream>
#include <vector>

namespace atcoder {

// https://drken1215.hatenablog.com/entry/2019/03/20/202800
template<int MAX_ROW = 510, int MAX_COL = 510>
struct BitMatrix {
    int H, W;
    std::bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int h, int w) : H(h), W(w) {}
    const std::bitset<MAX_COL>& operator[](int i) const { return val[i]; }
    std::bitset<MAX_COL>& operator[](int i) { return val[i]; }
};

template<int MAX_ROW = 510, int MAX_COL = 510>
std::ostream& operator<<(std::ostream& os, BitMatrix<MAX_ROW, MAX_COL>& A) {
    os << std::endl;
    for (int i = 0; i < A.H; ++i) {
        for (int j = 0; j < A.W; ++j) {
            os << A[i][j] << ", ";
        }
        os << std::endl;
    }
    return os;
}

template<int MAX_ROW = 510, int MAX_COL = 510>
int GaussJordan(BitMatrix<MAX_ROW, MAX_COL> &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

template<int MAX_ROW = 510, int MAX_COL = 510>
int LinearEquation(const BitMatrix<MAX_ROW, MAX_COL>& A, const std::vector<bool>& b, std::vector<bool> &x) {
    int m = A.H, n = A.W;
    BitMatrix<MAX_ROW,MAX_COL> M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

    // answer
    x.assign(n, false);
    for (int row = 0, col = 0; row < rank; ++row) {
        while (M[row][col] == 0) ++col;
        x[col] = M[row][n];
    }
    return rank;
}

}  // namespace atcoder

#endif  // ATCODER_BITMATRIX_HPP
