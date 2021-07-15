#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <atcoder/all>

using namespace atcoder;
using namespace std;

using S = int;
using F = int;
S op(S a, S b) { return min(a,b); }
S e() { return numeric_limits<S>::max(); }
F id() { return numeric_limits<F>::max(); }
S mapping(F a, S b) {
    if (a==id()) return b;
    return a;
}
F composition(F a, F b) {
    if (a==id()) return b;
    if (b==id()) return a;
    return b;
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    RedBlackLazySegmentTree<S,op,e,F,mapping,composition,id,500000> tree;
    tree.build(a);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; cin >> l >> r;
            S val = tree.erase(r);
            tree.insert(l, val);
        }
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << tree.prod(l, r+1) << endl;
        }
        if (t == 2) {
            int pos, val; cin >> pos >> val;
            tree.apply(pos, pos+1, val);
        }
    }
    return 0;
}
