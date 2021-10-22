#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880"

#include <atcoder/segment_map>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace atcoder;
using namespace std;

int main() {
    int n, m, q; cin >> n >> m >> q;

    vector<int> d(m), a(m), b(m);
    for (int i = 0; i < m; i++) cin >> d[i] >> a[i] >> b[i], --a[i], --b[i];

    vector<int> e(q), s(q), t(q);
    for (int i = 0; i < q; i++) cin >> e[i] >> s[i] >> t[i], --s[i], --t[i];

    using T = tuple<int,int,int>; // time, type, idx
    vector<T> events;
    for (int i = 0; i < m; i++) events.emplace_back(d[i], 1, i);
    for (int i = 0; i < q; i++) events.emplace_back(e[i], 0, i);
    sort(events.begin(), events.end());

    SegmentMap mp(false);
    vector<int> ans(q);
    for (auto [time, type, idx] : events) {
        if (type == 0) {
            // query
            ans[idx] = s[idx] > t[idx] or mp.same(s[idx], t[idx]);
        }
        if (type == 1) {
            // insert
            mp.insert(a[idx], b[idx]);
        }
    }

    for (int i = 0; i < q; i++) cout << (ans[i] ? "Yes" : "No") << '\n';
}
