#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <atcoder/math_enhanced>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y, m; cin >> x >> y >> m;
        cout << mod_log(x, y, m) << endl;
    }
}
