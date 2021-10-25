---
title: 2進数上の行列演算
documentation_of: //atcoder/bitmatrix.hpp
---

# 2進数上の行列演算

  $\mathbb{F}_2$ 上での行列演算を `std::bitset` を用いて高速に行う.

  行列のランクを求めたり, 連立一次方程式を解いたりするときに使う.

## コンストラクタ

  ```cpp
  BitMatirx<MAX_ROW, MAX_COL> A(H, W);
  ```

- ### 概要

  $H$ 行 $W$ 列の行列を作る. 初期値は `0`.

- ### 計算量

  $O(HW/64)$

## ランクの計算

  ```cpp
  int GaussJordan(BitMatrix<MAX_ROW, MAX_COL>& A)
  ```

- ### 概要

  行列 $A$ のランクを求める.

  副作用として, 行列 $A$ は行基本変形が適用された標準形となる.

- ### 計算量
 
  ランクを $r \le \min(H,W)$ として $O(rHW/64)$.

## 連立一次方程式の解き方
  ```cpp
  int linear_equation(const BitMatrix<MAX_ROW, MAX_COL>& A, 
                      const std::vector<bool>& b,
                      std::vector<bool>& x)
  ```

- ### 概要

  $H$ 行 $W$ 列の行列 $A$ と $b \in \mathbb{F}_2^W$ に対して,
  $Ax = b$ を満たす解 $x \in \mathbb{F}_2^H$ を一つ求め, 行列 $A$ のランクを返す.

  解が存在しない場合は `-1` を返す.

- ### 計算量

  行列 $A$ のランクを $r \le \min(H,W)$ として $O(rHW/64)$.
