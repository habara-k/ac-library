#ifndef ATCODER_MATH_ENHANCED_HPP
#define ATCODER_MATH_ENHANCED_HPP 1

#include<numeric>
#include<ext/pb_ds/assoc_container.hpp>

namespace atcoder {

// https://ei1333.github.io/library/math/combinatorics/mod-log.cpp
int64_t mod_log(int64_t a, int64_t b, int64_t p) {
    ((a %= p) += p) %= p;
    ((b %= p) += p) %= p;
    int64_t g = 1;
    for (int64_t i = p; i; i /= 2) (g *= a) %= p;
    g = std::gcd(g, p);

    int64_t t = 1, c = 0;
    for (; t % g; c++) {
        if (t == b) return c;
        (t *= a) %= p;
    }

    if (b % g) return -1;

    t /= g;
    b /= g;
    p /= g;

    int64_t h = 0, gs = 1;

    for (; h * h < p; h++) (gs *= a) %= p;
    __gnu_pbds::gp_hash_table<int64_t, int64_t> bs;
    for (int64_t s = 0, e = b; s < h; bs[e] = ++s) {
        (e *= a) %= p;
    }

    for (int64_t s = 0, e = t; s < p;) {
        (e *= gs) %= p;
        s += h;
        if (bs.find(e) != bs.end()) return c + s - bs[e];
    }

    return -1;
}

template<class T>
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

}  // namespace atcoder

#endif  // ATCODER_MATH_ENHANCED_HPP
