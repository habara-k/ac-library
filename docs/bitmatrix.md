---
title: 2進数上の行列演算
documentation_of: //atcoder/bitmatrix.hpp
---

## 概要

$\mathbb{F}_2$ 上での行列演算を `std::bitset` を用いて高速に行う.

行列のランクを求めたり, 連立一次方程式を解いたりするときに使う.

- `BitMatrix(H,W)`: $H$ 行 $W$ 列の行列を作る. 初期値は `0`.
- `GaussJordan(A)`: 行列 $A$ のランクを求める.
- `LinearEquation(A, b, x)`: $Ax = b$ の解 $x$ を一つ見つけて `x` に書き込み, $A$ のランクを返す. 
解がない場合は `-1` を返す.


## 計算量
- `BitMatrix(H,W)`: $O(HW/64)$
- `GaussJordan(A)`: $O(\min(H,W)HW/64)$.
- `LinearEquation(A, b, x)`: $O(\min(H,W)HW/64)$.
