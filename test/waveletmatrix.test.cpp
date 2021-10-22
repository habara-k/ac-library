#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <atcoder/waveletmatrix>
#include <iostream>
#include <vector>

using namespace atcoder;
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    WaveletMatrix<int, 30> mat(a);

    int q; cin >> q;
    while (q--) {
        int l, r, d; cin >> l >> r >> d;
        auto check = [&](int k) -> bool {
            return mat.range_freq(l, r+1, max(d-k, 0), d+k+1) > 0;
        };
        int ok = 1e6, ng = -1;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        cout << ok << endl;
    }
    return 0;
}
