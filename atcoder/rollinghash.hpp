#ifndef ATCODER_ROLLINGHASH_HPP
#define ATCODER_ROLLINGHASH_HPP 1

namespace atcoder {

using namespace std;

struct RollingHash {
    using u64 = uint64_t;
    using u128 = __uint128_t;

    template<typename S>
    RollingHash(const S &s, u64 base) {
        int n = s.size();
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

    static u64 gen_base() {
        mt19937 random{random_device{}()};
        uniform_int_distribution<u64> dist(2, MOD-2);
        return dist(random);
    }

private:
    vector<u64> hash, pow;
    static const u64 MOD = (1ul << 61) - 1;

    static u64 mul(u128 a, u128 b) {
        u128 t = a * b;
        t = (t >> 61) + (t & MOD);
        if (t >= MOD) t -= MOD;
        return t;
    }
};

}  // namespace atcoder

#endif  // ATCODER_ROLLINGHASH_HPP
