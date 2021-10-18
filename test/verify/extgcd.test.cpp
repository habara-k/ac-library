#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <atcoder/math_enhanced>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int x, y;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}
