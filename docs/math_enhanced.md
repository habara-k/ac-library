---
title: Math Enhanced
documentation_of: //atcoder/math_enhanced.hpp
---

## 概要

- `mod_log(a, b, p)` : $a^x \equiv b \bmod p$
を満たす最小の非負整数 $x$ を返す. 
そのような $x$ が存在しない場合は -1 を返す.
- `extgcd(a, b, x, y)` : $ax + by = gcd(x,y)$
を満たす $x, y$ を求め, $gcd(x, y)$ を返す.
 
## 制約

- `mod_log(a, b, p)` : $p$ は正整数.
- `extgcd(a, b, x, y)` : $a, b$ は非負整数.

## 計算量

- `mod_log(a, b, p)` : $O(\sqrt{p})$
- `extgcd(a, b, x, y)` : $O(\log \min(a, b))$


