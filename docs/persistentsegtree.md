---
title: 永続セグメント木
documentation_of: //atcoder/persistentsegtree.hpp
---

## 概要

永続化したセグメント木.

- `build(n)` : 長さ $n$ の配列を単位元 $e()$ で初期化し, 根のポインタを返す.
- `build(v)` : 配列 $v_1, \dots, v_n$ で初期化し, 根のポインタを返す.
- `set(p, k, x)` : ポインタ $p$ がさす時点の木に対して,
$k$ 番目(0-origin)の要素を $x$ に更新する.
その後, 根のポインタを返す.
- `get(p, k)` : ポインタ $p$ がさす時点の木に対して,
$k$ 番目(0-origin)の要素を返す.
- `get(p, a, b)` : ポインタ $p$ がさす時点の木に対して,
区間 $a, \ldots, b-1$ (0-origin)の総積を返す.

## 制約

- モノイドをのせる.

## 計算量

- 初期化 `build(n), build(v)` : $O(n)$
- クエリ `set, get` : $O(\log n)$
