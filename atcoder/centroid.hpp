#ifndef ATCODER_CENTROID_HPP
#define ATCODER_CENTROID_HPP 1

#include <vector>

namespace atcoder {

std::vector<int> centroid(const std::vector<std::vector<int>>& g) {
    const int n = int(g.size());
    std::vector<int> sz(n,1), ret;
    auto dfs = [&](auto self, int u, int p) -> int {
        bool isCent = true;
        for (int v : g[u]) {
            if (v == p) continue;
            sz[u] += self(self, v, u);
            if (sz[v] > n / 2) isCent = false;
        }
        if (n - sz[u] > n / 2) isCent = false;
        if (isCent) ret.emplace_back(u);
        return sz[u];
    };
    dfs(dfs, 0, -1);
    return ret;
}

}  // namespace atcoder

#endif  // ATCODER_CENTROID_HPP
