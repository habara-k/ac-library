---
title: 組み合わせ
documentation_of: //atcoder/combination.hpp
---

## 概要

- `fact(k)`: $k!$
- `rfact(k)`: $1/k!$
- `inv(k)`: $1/k$
- `P(n, r)`: ${}_nP_r$
- `C(n, r)`: ${}_nC_r$
- `H(n, r)`: ${}_nH_r$

## 制約

- 型テンプレート `T` には素数を法とする `modint` を渡す.
- `Combination(sz)` で初期化した `sz` より大きい値を使用してはならない.
- `modint` の法 $P$ 以上の `sz` で初期化してはいけない.

## 計算量

- `Combination(sz)`: $O(\mathrm{sz})$
- クエリ: $O(1)$