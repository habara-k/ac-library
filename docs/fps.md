---
title: 形式的冪級数
documentation_of: //atcoder/fps.hpp
---

## 概要

NTTの高速な実装. 

以下の演算に含まれる引数 `d` は, 
演算の結果を $d-1$ 次まで求めることを意味する.

`d` を渡さなかった場合, 演算の結果は $f(x)$ と同じ精度に丸められる.

- `FPS::inv(d)` : $1/f(x)$
- `FPS::log(d)` : $\log(f(x))$
- `FPS::exp(d)` : $\exp(f(x))$
- `FPS::pow(k, d)` : $f(x)^k$
- `FPS::multiply(g, d)` : $f(x) * g(x)$
- `bostan_mori(p, q, k)` : $p(x) / q(x)$ の $x^k$ の係数を求める.


## 制約

- 型テンプレート `T` には NTT-friendly な `modint` を渡す.
- `FPS::inv` : 定数項が $0$ でない.
- `FPS::log` : 定数項が $1$ である.
- `FPS::exp` : 定数項が $0$ である.
- `bostan_mori(p, q, k)` : $q(x)$ の定数項が $0$ でない.

## 計算量

$n := \mathrm{deg} f(x)$ とした場合,

- `FPS::inv()` : $O(n \log n)$
- `FPS::log()` : $O(n \log n)$
- `FPS::exp()` : $O(n \log n)$
- `FPS::pow(k)` : $O(n \log n)$
- `FPS::multiply(g)` : $O(n \log n)$

$n := \max(\mathrm{deg} p(x), \mathrm{deg} q(x))$ とした場合,
- `bostan_mori(p, q, k)` : $O(n \log n \log k)$



