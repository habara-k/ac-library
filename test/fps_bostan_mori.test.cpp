#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <atcoder/fps>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
    int d; long long k;
    cin >> d >> k;
    fps a(d), c(d+1);
    for (int i = 0; i < d; i++) { int t; cin >> t; a[i] = t; }
    for (int i = 0; i < d; i++) { int t; cin >> t; c[i+1] = -t; }
    c[0] = 1;
    a = convolution(a, c);
    a.resize(d);

    cout << bostan_mori(a, c, k).val() << endl;
}
