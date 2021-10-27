---
title: セグメント赤黒木
documentation_of: //atcoder/rb_segtree.hpp
---

## 概要

挿入と削除が $O(\log N)$ でできるセグメント木.

- `insert(k, x)` : $k$ 番目に $x$ を挿入する.
- `erase(k)` : $k$ 番目の要素を削除する.
- `get(k)` : $k$ 番目の要素を取得する.
- `prod(l, r)` : 区間 $[l, r)$ に対応する総積を取得する.
- `build(v)` : 配列 $v$ で初期化する.


## 計算量

- `insert` : $O(\log n)$
- `erase` : $O(\log n)$
- `get` : $O(\log n)$
- `prod` : $O(\log n)$
- `build` : $O(n)$
