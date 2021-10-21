#ifndef ATCODER_TREEHASH_HPP
#define ATCODER_TREEHASH_HPP 1

#include <atcoder/centroid>
#include <algorithm>
#include <random>

namespace atcoder {

struct TreeHash {
    using u128 = __uint128_t;
    using u64 = uint64_t;

    explicit TreeHash(const std::vector<std::vector<int>>& g_, int seed=0) : g(g_) {
        int n = int(g.size());
        std::mt19937 random(seed);
        std::uniform_int_distribution<u64> dist(2, MOD-2);
        for (int i = 0; i < n; ++i) base.emplace_back(dist(random));
    }

    u64 get() {
        std::vector<u64> hash;
        for (int root : centroid(g)) {
            hash.emplace_back(dfs(root, -1, 0));
        }
        return *min_element(hash.begin(), hash.end());
    }

private:
    std::vector<u64> base;
    std::vector<std::vector<int>> g;
    static const u64 MOD = (1ull << 61) - 1;

    static u64 mul(u128 a, u128 b) {
        u128 t = a * b;
        t = (t >> 61) + (t & MOD);
        return u64(t >= MOD ? t - MOD : t);
    }

    u64 dfs(int u, int p, int d) {
        u64 hash = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            hash = mul(hash, dfs(v, u, d+1));
        }
        hash += base[d];
        return hash >= MOD ? hash - MOD : hash;
    }
};

}  // namespace atcoder

#endif  // ATCODER_TREEHASH_HPP
