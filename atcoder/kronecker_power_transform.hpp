#ifndef ATCODER_KRONECKER_POWER_TRANSFORM_HPP
#define ATCODER_KRONECKER_POWER_TRANSFORM_HPP 1

#include <vector>
#include <functional>

namespace atcoder {

template<class T>
std::vector<T> kronecker_power_transform(std::vector<T> a, std::function<void(T&,T&)>&& f) {
    int n = int(a.size());
    assert((n & (n-1)) == 0);
    for (int block = 1; block < n; block *= 2) {
        for (int l = 0; l < n; l += 2 * block) {
            for (int i = l; i < l + block; i++) {
                f(a[i], a[i+block]);
            }
        }
    }
    return a;
}


template<class T>
std::vector<T> zeta_transform(std::vector<T> a, bool upper = true) {
    // b[s] = sum_{s \subset t} a[t]
    if (upper) return kronecker_power_transform<T>(a, [](T& x, T& y) { x += y; });

    // b[s] = sum_{t \subset s} a[t]
    return kronecker_power_transform<T>(a, [](T& x, T& y) { y += x; });
}

template<class T>
std::vector<T> mobius_transform(std::vector<T> b, bool upper = true) {
    // b[s] = sum_{s \subset t} a[t]
    if (upper) return kronecker_power_transform<T>(b, [](T& x, T& y) { x -= y; });

    // b[s] = sum_{t \subset s} a[t]
    return kronecker_power_transform<T>(b, [](T& x, T& y) { y -= x; });
}

template<class T>
std::vector<T> hadamard_transform(std::vector<T> a, bool inv = false) {
    auto ret = kronecker_power_transform<T>(a, [](T& x, T& y) { T t = x + y; y = x - y; x = t; });
    if (inv) {
        for (auto& e : ret) e /= a.size();
    }
    return ret;
}

template<class T>
std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    auto ha = hadamard_transform(a);
    auto hb = hadamard_transform(b);
    for (int i = 0; i < int(ha.size()); i++) ha[i] *= hb[i];
    return hadamard_transform(ha, true);
}

}  // namespace atcoder

#endif  // ATCODER_KRONECKER_POWER_TRANSFORM_HPP
