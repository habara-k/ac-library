#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include <atcoder/bitmatrix>
#include <vector>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
    while (true) {
        int m, n, d; cin >> m >> n >> d;
        if (m == 0) break;

        BitMatrix<625,625> A(n*m, n*m);
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < m; j1++) {
                A[i1*m + j1][i1*m + j1] = 1;
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        if (abs(i1 - i2) + abs(j1 - j2) == d) {
                            A[i1*m + j1][i2*m + j2] = 1;
                        }
                    }
                }
            }
        }
        vector<bool> b(n*m), x;
        for (int i = 0; i < n*m; i++) {
            int f; cin >> f; b[i] = f;
        }

        int rank = LinearEquation(A, b, x);
        cout << (rank != -1) << endl;
    }
}
