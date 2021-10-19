#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <atcoder/rerooting>
#include <iostream>

using namespace atcoder;
using namespace std;

int merge(int a, int b) { return max(a, b); }
int id() { return 0; }
int mapping(int a, int d) { return a + d; }

int main() {
    int n; cin >> n;

    re_rooting<int,merge,id,int,mapping> tree(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        tree.add_edge(u, v, 1);
    }

    for (auto a : tree.solve()) {
        cout << (n-1) * 2 - a << endl;
    }
}
