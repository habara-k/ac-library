#ifndef ATCODER_KRONECKER_POWER_TRANSFORM_HPP
#define ATCODER_KRONECKER_POWER_TRANSFORM_HPP 1

#include <vector>
#include <functional>

namespace atcoder {

template<class T, void (*f)(T&, T&)>
void kronecker_power_transform(std::vector<T>& a) {
    int n = int(a.size());
    assert((n & (n-1)) == 0);
    for (int block = 1; block < n; block *= 2) {
        for (int l = 0; l < n; l += 2 * block) {
            for (int i = l; i < l + block; i++) {
                f(a[i], a[i+block]);
            }
        }
    }
}

template<class T> struct ZetaTransform {
    static inline void f(T& x, T& y) { x += y; }
    static inline void g(T& x, T& y) { y += x; }
    static void apply(std::vector<T>& a, bool upper = true) {
        if (upper) {
            // b[s] = sum_{s \subset t} a[t]
            kronecker_power_transform<T,f>(a);
        } else {
            // b[s] = sum_{t \subset s} a[t]
            kronecker_power_transform<T,g>(a);
        }
    }
};

template<class T> struct MobiusTransform {
    static inline void f(T& x, T& y) { x -= y; }
    static inline void g(T& x, T& y) { y -= x; }
    static void apply(std::vector<T>& b, bool upper = true) {
        if (upper) {
            // b[s] = sum_{s \subset t} a[t]
            kronecker_power_transform<T,f>(b);
        } else {
            // b[s] = sum_{t \subset s} a[t]
            kronecker_power_transform<T,g>(b);
        }
    }
};

template<class T> struct HadamardTransform {
    static inline void f(T& x, T& y) { T t = x + y; y = x - y; x = t; }
    static void apply(std::vector<T>& a, bool inv = false) {
        kronecker_power_transform<T,f>(a);
        if (inv) {
            for (auto &e : a) e /= a.size();
        }
    }
};

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
void xor_convolution(std::vector<T>& a, std::vector<T>& b) {
    // a'[k] := \sum_{i xor j = k} a[i]b[j]
    // b': undefined
    assert(a.size() == b.size());
    HadamardTransform<T>::apply(a);
    HadamardTransform<T>::apply(b);
    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];
    HadamardTransform<T>::apply(a, true);
}

}  // namespace atcoder

#endif  // ATCODER_KRONECKER_POWER_TRANSFORM_HPP
