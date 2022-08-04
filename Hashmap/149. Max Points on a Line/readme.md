# 149. Max Points on a Line

对于一个点, 我们是不知道斜率的。 需要找到斜率，至少需要两个点。所以我们可以对于每一个点， 我们按照斜率归类。

## 要注意一些细节

- 如果用 dy/dx 代表斜率， 那精度会不够，我们要用最简分数来表示

```cpp
            int a = dy/(gcd(dx, dy));
            int b = dx/(gcd(dx, dy));
            mp[make_pair(a,b)]++;
```
