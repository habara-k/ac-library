---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps_bostan_mori.test.cpp
    title: test/fps_bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps_exp.test.cpp
    title: test/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps_inv.test.cpp
    title: test/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps_log.test.cpp
    title: test/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps_pow.test.cpp
    title: test/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/abs/1301.5804
    - https://opt-cp.com/fps-fast-algorithms
  bundledCode: "#line 1 \"atcoder/fps.hpp\"\n\n\n\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\n\nnamespace atcoder {\n\n// https://opt-cp.com/fps-fast-algorithms\n\
    template<class T>\nstruct FormalPowerSeries : std::vector<T> {\n    using std::vector<T>::vector;\n\
    \    using std::vector<T>::operator=;\n    using F = FormalPowerSeries;\n\n  \
    \  F operator-() const {\n        F res(*this);\n        for (auto &e : res) e\
    \ = -e;\n        return res;\n    }\n    F &operator*=(const T &g) {\n       \
    \ for (auto &e : *this) e *= g;\n        return *this;\n    }\n    F &operator/=(const\
    \ T &g) {\n        assert(g != T(0));\n        *this *= g.inv();\n        return\
    \ *this;\n    }\n    F &operator+=(const F &g) {\n        int n = int(this->size()),\
    \ m = int(g.size());\n        for (int i = 0; i < std::min(n, m); i++) (*this)[i]\
    \ += g[i];\n        return *this;\n    }\n    F &operator-=(const F &g) {\n  \
    \      int n = int(this->size()), m = int(g.size());\n        for (int i = 0;\
    \ i < std::min(n, m); i++) (*this)[i] -= g[i];\n        return *this;\n    }\n\
    \    F &operator<<=(const int d) {\n        int n = int(this->size());\n     \
    \   if (d >= n) *this = F(n);\n        this->insert(this->begin(), d, 0);\n  \
    \      this->resize(n);\n        return *this;\n    }\n    F &operator>>=(const\
    \ int d) {\n        int n = int(this->size());\n        this->erase(this->begin(),\
    \ this->begin() + std::min(n, d));\n        this->resize(n);\n        return *this;\n\
    \    }\n\n    // O(n log n)\n    F inv(int d = -1) const {\n        int n = int(this->size());\n\
    \        assert(n != 0 && (*this)[0] != 0);\n        if (d == -1) d = n;\n   \
    \     assert(d >= 0);\n        F res{(*this)[0].inv()};\n        for (int m =\
    \ 1; m < d; m *= 2) {\n            F f(this->begin(), this->begin() + std::min(n,\
    \ 2*m));\n            F g(res);\n            f.resize(2*m), internal::butterfly(f);\n\
    \            g.resize(2*m), internal::butterfly(g);\n            for (int i =\
    \ 0; i < 2 * m; i++) f[i] *= g[i];\n            internal::butterfly_inv(f);\n\
    \            f.erase(f.begin(), f.begin() + m);\n            f.resize(2*m), internal::butterfly(f);\n\
    \            for (int i = 0; i < 2 * m; i++) f[i] *= g[i];\n            internal::butterfly_inv(f);\n\
    \            T iz = T(2*m).inv(); iz *= -iz;\n            for (int i = 0; i <\
    \ m; i++) f[i] *= iz;\n            res.insert(res.end(), f.begin(), f.begin()\
    \ + m);\n        }\n        res.resize(d);\n        return res;\n    }\n\n   \
    \ // fast: FMT-friendly modulus only\n    // O(n log n)\n    F &multiply_inplace(const\
    \ F &g, int d = -1) {\n        int n = int(this->size());\n        if (d == -1)\
    \ d = n;\n        assert(d >= 0);\n        *this = convolution(move(*this), g);\n\
    \        this->resize(d);\n        return *this;\n    }\n    F multiply(const\
    \ F &g, const int d = -1) const { return F(*this).multiply_inplace(g, d); }\n\
    \    // O(n log n)\n    F &divide_inplace(const F &g, int d = -1) {\n        int\
    \ n = int(this->size());\n        if (d == -1) d = n;\n        assert(d >= 0);\n\
    \        *this = convolution(move(*this), g.inv(d));\n        this->resize(d);\n\
    \        return *this;\n    }\n    F divide(const F &g, const int d = -1) const\
    \ { return F(*this).divide_inplace(g, d); }\n\n    // O(n)\n    F &integ_inplace()\
    \ {\n        int n = int(this->size());\n        assert(n > 0);\n        if (n\
    \ == 1) return *this = F{0};\n        this->insert(this->begin(), 0);\n      \
    \  this->pop_back();\n        std::vector<T> inv(n);\n        inv[1] = 1;\n  \
    \      int p = T::mod();\n        for (int i = 2; i < n; ++i) inv[i] = - inv[p%i]\
    \ * (p/i);\n        for (int i = 2; i < n; ++i) (*this)[i] *= inv[i];\n      \
    \  return *this;\n    }\n    F integ() const { return F(*this).integ_inplace();\
    \ }\n\n    // O(n)\n    F &deriv_inplace() {\n        int n = int(this->size());\n\
    \        assert(n > 0);\n        for (int i = 2; i < n; ++i) (*this)[i] *= i;\n\
    \        this->erase(this->begin());\n        this->push_back(0);\n        return\
    \ *this;\n    }\n    F deriv() const { return F(*this).deriv_inplace(); }\n\n\
    \    // O(n log n)\n    F &log_inplace(int d = -1) {\n        if (d != -1) this->resize(d);\n\
    \        int n = int(this->size());\n        assert(n > 0 && (*this)[0] == 1);\n\
    \        if (d == -1) d = n;\n        assert(d >= 0);\n        if (d < n) this->resize(d);\n\
    \        F f_inv = this->inv();\n        this->deriv_inplace();\n        this->multiply_inplace(f_inv);\n\
    \        this->integ_inplace();\n        return *this;\n    }\n    F log(const\
    \ int d = -1) const { return F(*this).log_inplace(d); }\n\n    // O(n log n)\n\
    \    // https://arxiv.org/abs/1301.5804 (Figure 1, right)\n    F &exp_inplace(int\
    \ d = -1) {\n        int n = int(this->size());\n        assert(n > 0 && (*this)[0]\
    \ == 0);\n        if (d == -1) d = n;\n        assert(d >= 0);\n        F g{1},\
    \ g_fft;\n        this->resize(d);\n        (*this)[0] = 1;\n        F h_drv(this->deriv());\n\
    \        for (int m = 1; m < d; m *= 2) {\n            // prepare\n          \
    \  F f_fft(this->begin(), this->begin() + m);\n            f_fft.resize(2*m),\
    \ internal::butterfly(f_fft);\n\n            // Step 2.a'\n            if (m >\
    \ 1) {\n                F _f(m);\n                for (int i = 0; i < m; i++)\
    \ _f[i] = f_fft[i] * g_fft[i];\n                internal::butterfly_inv(_f);\n\
    \                _f.erase(_f.begin(), _f.begin() + m/2);\n                _f.resize(m),\
    \ internal::butterfly(_f);\n                for (int i = 0; i < m; i++) _f[i]\
    \ *= g_fft[i];\n                internal::butterfly_inv(_f);\n               \
    \ _f.resize(m/2);\n                _f /= T(-m) * m;\n                g.insert(g.end(),\
    \ _f.begin(), _f.begin() + m/2);\n            }\n\n            // Step 2.b'--d'\n\
    \            F t(this->begin(), this->begin() + m);\n            t.deriv_inplace();\n\
    \            {\n                // Step 2.b'\n                F r{h_drv.begin(),\
    \ h_drv.begin() + m-1};\n                // Step 2.c'\n                r.resize(m);\
    \ internal::butterfly(r);\n                for (int i = 0; i < m; i++) r[i] *=\
    \ f_fft[i];\n                internal::butterfly_inv(r);\n                r /=\
    \ -m;\n                // Step 2.d'\n                t += r;\n               \
    \ t.insert(t.begin(), t.back()); t.pop_back();\n            }\n\n            //\
    \ Step 2.e'\n            if (2*m < d || m == 1) {\n                t.resize(2*m);\
    \ internal::butterfly(t);\n                g_fft = g; g_fft.resize(2*m); internal::butterfly(g_fft);\n\
    \                for (int i = 0; i < 2 * m; i++) t[i] *= g_fft[i];\n         \
    \       internal::butterfly_inv(t);\n                t.resize(m);\n          \
    \      t /= 2*m;\n            }\n            else { // This division of cases\
    \ will only speed things up by a few percent.\n                F g1(g.begin()\
    \ + m/2, g.end());\n                F s1(t.begin() + m/2, t.end());\n        \
    \        t.resize(m/2);\n                g1.resize(m), internal::butterfly(g1);\n\
    \                t.resize(m),  internal::butterfly(t);\n                s1.resize(m),\
    \ internal::butterfly(s1);\n                for (int i = 0; i < m; i++) s1[i]\
    \ = g_fft[i] * s1[i] + g1[i] * t[i];\n                for (int i = 0; i < m; i++)\
    \ t[i] *= g_fft[i];\n                internal::butterfly_inv(t);\n           \
    \     internal::butterfly_inv(s1);\n                for (int i = 0; i < m / 2;\
    \ i++) t[i+m/2] += s1[i];\n                t /= m;\n            }\n\n        \
    \    // Step 2.f'\n            F v(this->begin() + m, this->begin() + std::min<int>(d,\
    \ 2*m)); v.resize(m);\n            t.insert(t.begin(), m-1, 0); t.push_back(0);\n\
    \            t.integ_inplace();\n            for (int i = 0; i < m; i++) v[i]\
    \ -= t[m+i];\n\n            // Step 2.g'\n            v.resize(2*m); internal::butterfly(v);\n\
    \            for (int i = 0; i < 2 * m; i++) v[i] *= f_fft[i];\n            internal::butterfly_inv(v);\n\
    \            v.resize(m);\n            v /= 2*m;\n\n            // Step 2.h'\n\
    \            for (int i = 0; i < std::min(d - m, m); i++) (*this)[m+i] = v[i];\n\
    \        }\n        return *this;\n    }\n    F exp(const int d = -1) const {\
    \ return F(*this).exp_inplace(d); }\n\n    // O(n log n)\n    F &pow_inplace(long\
    \ long k, int d = -1) {\n        if (d != -1) this->resize(d);\n        int n\
    \ = int(this->size());\n        if (d == -1) d = n;\n        assert(d >= 0);\n\
    \        int l = 0;\n        while ((*this)[l] == 0) ++l;\n        if (l > d/k)\
    \ return *this = F(d);\n        T ic = (*this)[l].inv();\n        T pc = (*this)[l].pow(k);\n\
    \        this->erase(this->begin(), this->begin() + l);\n        *this *= ic;\n\
    \        this->log_inplace();\n        *this *= k;\n        this->exp_inplace();\n\
    \        *this *= pc;\n        this->insert(this->begin(), l*k, 0);\n        this->resize(d);\n\
    \        return *this;\n    }\n    F pow(const long long k, const int d = -1)\
    \ const { return F(*this).pow_inplace(k, d); }\n\n    F operator*(const T &g)\
    \ const { return F(*this) *= g; }\n    F operator/(const T &g) const { return\
    \ F(*this) /= g; }\n    F operator+(const F &g) const { return F(*this) += g;\
    \ }\n    F operator-(const F &g) const { return F(*this) -= g; }\n    F operator<<(const\
    \ int d) const { return F(*this) <<= d; }\n    F operator>>(const int d) const\
    \ { return F(*this) >>= d; }\n};\n\nusing fps = FormalPowerSeries<modint998244353>;\n\
    \ntemplate<typename T>\nT bostan_mori(FormalPowerSeries<T> p, FormalPowerSeries<T>\
    \ q, long long n) {\n    while (n > 0) {\n        auto q_ = q;\n        for (int\
    \ i = 1; i < int(q.size()); i += 2) q_[i] *= -1;\n\n        q = convolution(move(q),\
    \ q_);\n        int i;\n        for (i = 0; 2*i < (int)(q.size()); i++) q[i] =\
    \ q[2*i];\n        q.resize(i);\n\n        p = convolution(move(p), move(q_));\n\
    \        for (i = 0; 2*i + (n&1) < (int)(p.size()); i++) p[i] = p[2*i + (n&1)];\n\
    \        p.resize(i);\n        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n\n\
    }  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_FPS_HPP\n#define ATCODER_FPS_HPP 1\n\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\n\nnamespace atcoder {\n\n// https://opt-cp.com/fps-fast-algorithms\n\
    template<class T>\nstruct FormalPowerSeries : std::vector<T> {\n    using std::vector<T>::vector;\n\
    \    using std::vector<T>::operator=;\n    using F = FormalPowerSeries;\n\n  \
    \  F operator-() const {\n        F res(*this);\n        for (auto &e : res) e\
    \ = -e;\n        return res;\n    }\n    F &operator*=(const T &g) {\n       \
    \ for (auto &e : *this) e *= g;\n        return *this;\n    }\n    F &operator/=(const\
    \ T &g) {\n        assert(g != T(0));\n        *this *= g.inv();\n        return\
    \ *this;\n    }\n    F &operator+=(const F &g) {\n        int n = int(this->size()),\
    \ m = int(g.size());\n        for (int i = 0; i < std::min(n, m); i++) (*this)[i]\
    \ += g[i];\n        return *this;\n    }\n    F &operator-=(const F &g) {\n  \
    \      int n = int(this->size()), m = int(g.size());\n        for (int i = 0;\
    \ i < std::min(n, m); i++) (*this)[i] -= g[i];\n        return *this;\n    }\n\
    \    F &operator<<=(const int d) {\n        int n = int(this->size());\n     \
    \   if (d >= n) *this = F(n);\n        this->insert(this->begin(), d, 0);\n  \
    \      this->resize(n);\n        return *this;\n    }\n    F &operator>>=(const\
    \ int d) {\n        int n = int(this->size());\n        this->erase(this->begin(),\
    \ this->begin() + std::min(n, d));\n        this->resize(n);\n        return *this;\n\
    \    }\n\n    // O(n log n)\n    F inv(int d = -1) const {\n        int n = int(this->size());\n\
    \        assert(n != 0 && (*this)[0] != 0);\n        if (d == -1) d = n;\n   \
    \     assert(d >= 0);\n        F res{(*this)[0].inv()};\n        for (int m =\
    \ 1; m < d; m *= 2) {\n            F f(this->begin(), this->begin() + std::min(n,\
    \ 2*m));\n            F g(res);\n            f.resize(2*m), internal::butterfly(f);\n\
    \            g.resize(2*m), internal::butterfly(g);\n            for (int i =\
    \ 0; i < 2 * m; i++) f[i] *= g[i];\n            internal::butterfly_inv(f);\n\
    \            f.erase(f.begin(), f.begin() + m);\n            f.resize(2*m), internal::butterfly(f);\n\
    \            for (int i = 0; i < 2 * m; i++) f[i] *= g[i];\n            internal::butterfly_inv(f);\n\
    \            T iz = T(2*m).inv(); iz *= -iz;\n            for (int i = 0; i <\
    \ m; i++) f[i] *= iz;\n            res.insert(res.end(), f.begin(), f.begin()\
    \ + m);\n        }\n        res.resize(d);\n        return res;\n    }\n\n   \
    \ // fast: FMT-friendly modulus only\n    // O(n log n)\n    F &multiply_inplace(const\
    \ F &g, int d = -1) {\n        int n = int(this->size());\n        if (d == -1)\
    \ d = n;\n        assert(d >= 0);\n        *this = convolution(move(*this), g);\n\
    \        this->resize(d);\n        return *this;\n    }\n    F multiply(const\
    \ F &g, const int d = -1) const { return F(*this).multiply_inplace(g, d); }\n\
    \    // O(n log n)\n    F &divide_inplace(const F &g, int d = -1) {\n        int\
    \ n = int(this->size());\n        if (d == -1) d = n;\n        assert(d >= 0);\n\
    \        *this = convolution(move(*this), g.inv(d));\n        this->resize(d);\n\
    \        return *this;\n    }\n    F divide(const F &g, const int d = -1) const\
    \ { return F(*this).divide_inplace(g, d); }\n\n    // O(n)\n    F &integ_inplace()\
    \ {\n        int n = int(this->size());\n        assert(n > 0);\n        if (n\
    \ == 1) return *this = F{0};\n        this->insert(this->begin(), 0);\n      \
    \  this->pop_back();\n        std::vector<T> inv(n);\n        inv[1] = 1;\n  \
    \      int p = T::mod();\n        for (int i = 2; i < n; ++i) inv[i] = - inv[p%i]\
    \ * (p/i);\n        for (int i = 2; i < n; ++i) (*this)[i] *= inv[i];\n      \
    \  return *this;\n    }\n    F integ() const { return F(*this).integ_inplace();\
    \ }\n\n    // O(n)\n    F &deriv_inplace() {\n        int n = int(this->size());\n\
    \        assert(n > 0);\n        for (int i = 2; i < n; ++i) (*this)[i] *= i;\n\
    \        this->erase(this->begin());\n        this->push_back(0);\n        return\
    \ *this;\n    }\n    F deriv() const { return F(*this).deriv_inplace(); }\n\n\
    \    // O(n log n)\n    F &log_inplace(int d = -1) {\n        if (d != -1) this->resize(d);\n\
    \        int n = int(this->size());\n        assert(n > 0 && (*this)[0] == 1);\n\
    \        if (d == -1) d = n;\n        assert(d >= 0);\n        if (d < n) this->resize(d);\n\
    \        F f_inv = this->inv();\n        this->deriv_inplace();\n        this->multiply_inplace(f_inv);\n\
    \        this->integ_inplace();\n        return *this;\n    }\n    F log(const\
    \ int d = -1) const { return F(*this).log_inplace(d); }\n\n    // O(n log n)\n\
    \    // https://arxiv.org/abs/1301.5804 (Figure 1, right)\n    F &exp_inplace(int\
    \ d = -1) {\n        int n = int(this->size());\n        assert(n > 0 && (*this)[0]\
    \ == 0);\n        if (d == -1) d = n;\n        assert(d >= 0);\n        F g{1},\
    \ g_fft;\n        this->resize(d);\n        (*this)[0] = 1;\n        F h_drv(this->deriv());\n\
    \        for (int m = 1; m < d; m *= 2) {\n            // prepare\n          \
    \  F f_fft(this->begin(), this->begin() + m);\n            f_fft.resize(2*m),\
    \ internal::butterfly(f_fft);\n\n            // Step 2.a'\n            if (m >\
    \ 1) {\n                F _f(m);\n                for (int i = 0; i < m; i++)\
    \ _f[i] = f_fft[i] * g_fft[i];\n                internal::butterfly_inv(_f);\n\
    \                _f.erase(_f.begin(), _f.begin() + m/2);\n                _f.resize(m),\
    \ internal::butterfly(_f);\n                for (int i = 0; i < m; i++) _f[i]\
    \ *= g_fft[i];\n                internal::butterfly_inv(_f);\n               \
    \ _f.resize(m/2);\n                _f /= T(-m) * m;\n                g.insert(g.end(),\
    \ _f.begin(), _f.begin() + m/2);\n            }\n\n            // Step 2.b'--d'\n\
    \            F t(this->begin(), this->begin() + m);\n            t.deriv_inplace();\n\
    \            {\n                // Step 2.b'\n                F r{h_drv.begin(),\
    \ h_drv.begin() + m-1};\n                // Step 2.c'\n                r.resize(m);\
    \ internal::butterfly(r);\n                for (int i = 0; i < m; i++) r[i] *=\
    \ f_fft[i];\n                internal::butterfly_inv(r);\n                r /=\
    \ -m;\n                // Step 2.d'\n                t += r;\n               \
    \ t.insert(t.begin(), t.back()); t.pop_back();\n            }\n\n            //\
    \ Step 2.e'\n            if (2*m < d || m == 1) {\n                t.resize(2*m);\
    \ internal::butterfly(t);\n                g_fft = g; g_fft.resize(2*m); internal::butterfly(g_fft);\n\
    \                for (int i = 0; i < 2 * m; i++) t[i] *= g_fft[i];\n         \
    \       internal::butterfly_inv(t);\n                t.resize(m);\n          \
    \      t /= 2*m;\n            }\n            else { // This division of cases\
    \ will only speed things up by a few percent.\n                F g1(g.begin()\
    \ + m/2, g.end());\n                F s1(t.begin() + m/2, t.end());\n        \
    \        t.resize(m/2);\n                g1.resize(m), internal::butterfly(g1);\n\
    \                t.resize(m),  internal::butterfly(t);\n                s1.resize(m),\
    \ internal::butterfly(s1);\n                for (int i = 0; i < m; i++) s1[i]\
    \ = g_fft[i] * s1[i] + g1[i] * t[i];\n                for (int i = 0; i < m; i++)\
    \ t[i] *= g_fft[i];\n                internal::butterfly_inv(t);\n           \
    \     internal::butterfly_inv(s1);\n                for (int i = 0; i < m / 2;\
    \ i++) t[i+m/2] += s1[i];\n                t /= m;\n            }\n\n        \
    \    // Step 2.f'\n            F v(this->begin() + m, this->begin() + std::min<int>(d,\
    \ 2*m)); v.resize(m);\n            t.insert(t.begin(), m-1, 0); t.push_back(0);\n\
    \            t.integ_inplace();\n            for (int i = 0; i < m; i++) v[i]\
    \ -= t[m+i];\n\n            // Step 2.g'\n            v.resize(2*m); internal::butterfly(v);\n\
    \            for (int i = 0; i < 2 * m; i++) v[i] *= f_fft[i];\n            internal::butterfly_inv(v);\n\
    \            v.resize(m);\n            v /= 2*m;\n\n            // Step 2.h'\n\
    \            for (int i = 0; i < std::min(d - m, m); i++) (*this)[m+i] = v[i];\n\
    \        }\n        return *this;\n    }\n    F exp(const int d = -1) const {\
    \ return F(*this).exp_inplace(d); }\n\n    // O(n log n)\n    F &pow_inplace(long\
    \ long k, int d = -1) {\n        if (d != -1) this->resize(d);\n        int n\
    \ = int(this->size());\n        if (d == -1) d = n;\n        assert(d >= 0);\n\
    \        int l = 0;\n        while ((*this)[l] == 0) ++l;\n        if (l > d/k)\
    \ return *this = F(d);\n        T ic = (*this)[l].inv();\n        T pc = (*this)[l].pow(k);\n\
    \        this->erase(this->begin(), this->begin() + l);\n        *this *= ic;\n\
    \        this->log_inplace();\n        *this *= k;\n        this->exp_inplace();\n\
    \        *this *= pc;\n        this->insert(this->begin(), l*k, 0);\n        this->resize(d);\n\
    \        return *this;\n    }\n    F pow(const long long k, const int d = -1)\
    \ const { return F(*this).pow_inplace(k, d); }\n\n    F operator*(const T &g)\
    \ const { return F(*this) *= g; }\n    F operator/(const T &g) const { return\
    \ F(*this) /= g; }\n    F operator+(const F &g) const { return F(*this) += g;\
    \ }\n    F operator-(const F &g) const { return F(*this) -= g; }\n    F operator<<(const\
    \ int d) const { return F(*this) <<= d; }\n    F operator>>(const int d) const\
    \ { return F(*this) >>= d; }\n};\n\nusing fps = FormalPowerSeries<modint998244353>;\n\
    \ntemplate<typename T>\nT bostan_mori(FormalPowerSeries<T> p, FormalPowerSeries<T>\
    \ q, long long n) {\n    while (n > 0) {\n        auto q_ = q;\n        for (int\
    \ i = 1; i < int(q.size()); i += 2) q_[i] *= -1;\n\n        q = convolution(move(q),\
    \ q_);\n        int i;\n        for (i = 0; 2*i < (int)(q.size()); i++) q[i] =\
    \ q[2*i];\n        q.resize(i);\n\n        p = convolution(move(p), move(q_));\n\
    \        for (i = 0; 2*i + (n&1) < (int)(p.size()); i++) p[i] = p[2*i + (n&1)];\n\
    \        p.resize(i);\n        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n\n\
    }  // namespace atcoder\n\n#endif  // ATCODER_FPS_HPP\n"
  dependsOn:
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: atcoder/fps.hpp
  requiredBy: []
  timestamp: '2021-10-21 18:06:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps_bostan_mori.test.cpp
  - test/fps_inv.test.cpp
  - test/fps_pow.test.cpp
  - test/fps_exp.test.cpp
  - test/fps_log.test.cpp
documentation_of: atcoder/fps.hpp
layout: document
redirect_from:
- /library/atcoder/fps.hpp
- /library/atcoder/fps.hpp.html
title: atcoder/fps.hpp
---
