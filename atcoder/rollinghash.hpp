#ifndef ATCODER_ROLLINGHASH_HPP
#define ATCODER_ROLLINGHASH_HPP 1

#include <random>

namespace atcoder {

struct RollingHash {
    using u128 = __uint128_t;
    using u64 = uint64_t;

    template<typename S>
    explicit RollingHash(const S &s, int seed=0) {
        std::mt19937 random(seed);
        std::uniform_int_distribution<u64> dist(2, MOD-2);
        u64 base = dist(random);
        int n = int(s.size());
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i+1] = mul(hash[i], base) + s[i];
            if (hash[i+1] >= MOD) hash[i+1] -= MOD;
            pow[i+1] = mul(pow[i], base);
        }
    }

    u64 get(int l, int r) const {
        u64 ret = hash[r] + MOD - mul(hash[l], pow[r-l]);
        return ret >= MOD ? ret - MOD : ret;
    }

private:
    std::vector<u64> hash, pow;

    static const u64 MOD = (1ull << 61) - 1;

    static u64 mul(u128 a, u128 b) {
        u128 t = a * b;
        t = (t >> 61) + (t & MOD);
        return u64(t >= MOD ? t - MOD : t);
    }
};

}  // namespace atcoder

#endif  // ATCODER_ROLLINGHASH_HPP
