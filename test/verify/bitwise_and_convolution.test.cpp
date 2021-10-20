#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <atcoder/modint>
#include <atcoder/kronecker_power_transform>
#include <iostream>
#include <vector>

using namespace atcoder;
using namespace std;

int main() {
    int n; cin >> n;
    using mint = modint998244353;
    std::vector<mint> a(1<<n), b(1<<n);
    for (int i = 0; i < 1<<n; i++) {
        int x; cin >> x; a[i] = x;
    }
    for (int i = 0; i < 1<<n; i++) {
        int x; cin >> x; b[i] = x;
    }
    bitwise_and_convolution(a, b);
    for (int i = 0; i < 1<<n; i++) {
        cout << a[i].val() << ' ';
    }
    cout << '\n';
}
