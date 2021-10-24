#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <atcoder/redblacklazysegtree>
#include <iostream>
#include <limits>

using namespace atcoder;
using namespace std;

int op(int a, int b) { return min(a,b); }
int e() { return numeric_limits<int>::max(); }
int id() { return numeric_limits<int>::max(); }
int mapping(int a, int b) {
    if (a==id()) return b;
    return a;
}
int composition(int a, int b) {
    if (a==id()) return b;
    if (b==id()) return a;
    return b;
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    rb_lazy_segtree<int,op,e,int,mapping,composition,id> tree(n);
    tree.build(a);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; cin >> l >> r;
            int val = tree.erase(r);
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
