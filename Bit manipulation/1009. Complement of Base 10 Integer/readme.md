# 1009. Complement of Base 10 Integer

此题是找到二进制的complement， 因为c++的int底层也是用二进制表示的，所以可以直接对于数字进行操作，无需额外的转化

### example
5 -> 101, complement is 010 in binary

### 思路
^(xor) 的基本使用 (不一样的是true/1)：
- 0^1 = 1
- 1^0 = 1
- 0^0 = 0
- 1^1 = 0

所以如果我们要找complement，我们会发现：
- x ^ x complement = 1111...111(x 长度的 1)
- x ^ 1111...111(x 长度的 1) = x complement
```
    ex: 101 ^ 111 = 010
```
用一下代码找到对应长度的 111...11

```cpp
        int x = 1;
        while (n > x)
        {
            x = x * 2 + 1; // 1 -> 11 -> 111 -> ...
        }
```
最后返回
```cpp
        return n ^ x;
```