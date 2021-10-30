#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <atcoder/rb_lazysegtree_reversible>
#include <atcoder/modint>
#include <iostream>
#include <limits>

using namespace atcoder;
using namespace std;

using mint = modint998244353;
struct node {
    mint x;
    int len;
};
node op(node a, node b) {
    return node{a.x + b.x, a.len + b.len};
}
node e() { return {0, 0}; }

struct affine {
    mint a, b;
};
bool operator!=(affine f, affine g) {
    return f.a != g.a or f.b != g.b;
}
affine id() { return affine{1, 0}; }
node mapping(affine f, node t) {
    return node{f.a * t.x + f.b * t.len, t.len};
}
affine composition(affine f, affine g) {
    return affine{f.a * g.a, f.b * g.a + g.b};
}

int main() {
    int n, q; cin >> n >> q;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[i].x = x, a[i].len = 1;
    }

    RBLazySegtreeReversible<node,op,e,affine,mapping,composition,id> tree(n+q);
    tree.build(a);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int i, x; cin >> i >> x;
            tree.insert(i, node{x, 1});
        }
        if (t == 1) {
            int i; cin >> i;
            tree.erase(i);
        }
        if (t == 2) {
            int l, r; cin >> l >> r;
            tree.reverse(l, r);
        }
        if (t == 3) {
            int l, r, b, c; cin >> l >> r >> b >> c;
            tree.apply(l, r, affine{b, c});
        }
        if (t == 4) {
            int l, r; cin >> l >> r;
            cout << tree.prod(l, r).x.val() << endl;
        }
    }
    return 0;
}
