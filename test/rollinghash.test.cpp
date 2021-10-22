#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include <atcoder/rollinghash>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    int n = int(T.size()), m = int(P.size());

    int seed = random_device{}();
    RollingHash rht(T, seed);
    RollingHash rhp(P, seed);

    for (int i = 0; i+m <= n; ++i) {
        if (rht.get(i, i+m) == rhp.get(0, m)) {
            cout << i << endl;
        }
    }
}
