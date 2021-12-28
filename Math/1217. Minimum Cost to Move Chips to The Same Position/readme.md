# 1217. Minimum Cost to Move Chips to The Same Position

这题目我归在了math下，其实是个找规律的题。我看到这个题目时候第一反应也很懵逼。但是其实遇到这种情况，不妨我们举个例子看看，例子来源于Maango16， 十分感谢。

### 例子

我们考虑假设需要把所以的coin都放到 position 0：
- 所有 position 0 的 coin 不用移动， 所以 cost = 0 
- 所有 position 1 的 coin 需要移动一格， 所以 cost = position 1 的 coin的个数
- 所有 position 2 的 coin 移动一次两格， 所以 cost = 0 
- 所有 position 3 的 coin， 先移动一次两格到position 1，再需要移动一格， 所以 cost = position 3 的 coin的个数

依此类推。。。

### 观察所得
我们观察例子发现了一下规律：

1. 如果是把所以的coin 移动到 0，那 cost = ```在odd position 上 coin 的个数的和```
2. 更进一步，如果是把所以的coin 移动到 一个 even position，那 cost 也是 ```在 odd position 上 coin 的个数的和```
3. 反之亦然。如果是把所以的coin 移动到 一个 odd position，那 cost 也是 ```在 even position 上 coin 的个数的和```
4. 所以此题的答案就是 min(```在 odd position 上 coin 的个数的和```,  ```在 even position 上 coin 的个数的和```)