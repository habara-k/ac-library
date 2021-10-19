#ifndef ATCODER_REROOTING_HPP
#define ATCODER_REROOTING_HPP 1

#include <vector>
#include <algorithm>

namespace atcoder {

using namespace std;

template<
        class T,
        T (*merge)(T,T),
        T (*id)(),
        class EdgeData,
        T (*mapping)(T,EdgeData)>
struct re_rooting {

    explicit re_rooting(int n) : re_rooting(vector<T>(n, id())) {}
    explicit re_rooting(const vector<T>& init) : g(init.size()), dp(init) {}

    void add_edge(int u, int v, EdgeData d) {
        add_edge(u, v, d, d);
    }
    void add_edge(int u, int v, EdgeData d, EdgeData e) {
        g[u].push_back((edge){v, d});
        g[v].push_back((edge){u, e});
    }

    // dp[u] := merge({ mapping(dp[e.to], e.data) | e in g[u] })
    vector<T> solve() {
        dfs_sub(0, -1);
        dfs_all(0, -1, id());
        return dp;
    }

private:
    struct edge {
        int to;
        EdgeData data;
        T lsum = id(), sub = id();
    };
    vector<vector<edge>> g;
    vector<T> dp;

    T dfs_sub(int u, int par) {
        for (edge& e : g[u]) {
            if (e.to == par) continue;
            dp[u] = merge(dp[u], mapping(dfs_sub(e.to, u), e.data));
        }
        return dp[u];
    }

    void dfs_all(int u, int par, T top) {
        dp[u] = id();
        for (edge& e : g[u]) {
            e.lsum = dp[u];
            e.sub = mapping(e.to == par ? top : dp[e.to], e.data);
            dp[u] = merge(dp[u], e.sub);
        }

        T rsum = id();
        reverse(g[u].begin(), g[u].end());
        for (edge& e : g[u]) {
            if (e.to != par) dfs_all(e.to, u, merge(e.lsum, rsum));
            rsum = merge(rsum, e.sub);
        }
    }
};

}  // namespace atcoder

#endif  // ATCODER_REROOTING_HPP
