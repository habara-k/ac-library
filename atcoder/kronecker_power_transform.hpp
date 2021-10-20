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

template<class T> struct SupersetZetaTransform {
    static inline void unit(T& x, T& y) { x += y; }
    static void apply(std::vector<T>& a) {
        // a'[s] = \sum_{s \subset t} a[t]
        kronecker_power_transform<T,unit>(a);
    }
};

template<class T> struct SubsetZetaTransform {
    static inline void unit(T& x, T& y) { y += x; }
    static void apply(std::vector<T>& a) {
        // a'[s] = \sum_{t \subset s} a[t]
        kronecker_power_transform<T,unit>(a);
    }
};

template<class T> struct SupersetMobiusTransform {
    static inline void unit(T& x, T& y) { x -= y; }
    static void apply(std::vector<T>& a) {
        // a[s] = \sum_{s \subset t} a'[t]
        kronecker_power_transform<T,unit>(a);
    }
};

template<class T> struct SubsetMobiusTransform {
    static inline void unit(T& x, T& y) { y -= x; }
    static void apply(std::vector<T>& a) {
        // a[s] = \sum_{t \subset s} a'[t]
        kronecker_power_transform<T,unit>(a);
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
void xor_convolution(std::vector<T>& a, std::vector<T>& b) {
    // a'[k] = \sum_{i xor j = k} a[i]b[j]
    // b' = undefined
    assert(a.size() == b.size());
    HadamardTransform<T>::apply(a);
    HadamardTransform<T>::apply(b);
    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];
    HadamardTransform<T>::apply(a, true);
}

template<class T>
void bitwise_and_convolution(std::vector<T>& a, std::vector<T>& b) {
    // a'[k] = \sum_{i and j = k} a[i]b[j]
    // b' = undefined
    assert(a.size() == b.size());
    SupersetZetaTransform<T>::apply(a);
    SupersetZetaTransform<T>::apply(b);
    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];
    SupersetMobiusTransform<T>::apply(a);
}

template<class T>
void bitwise_or_convolution(std::vector<T>& a, std::vector<T>& b) {
    // a'[k] = \sum_{i or j = k} a[i]b[j]
    // b' = undefined
    assert(a.size() == b.size());
    SubsetZetaTransform<T>::apply(a);
    SubsetZetaTransform<T>::apply(b);
    for (int i = 0; i < int(a.size()); i++) a[i] *= b[i];
    SubsetMobiusTransform<T>::apply(a);
}

}  // namespace atcoder

#endif  // ATCODER_KRONECKER_POWER_TRANSFORM_HPP
