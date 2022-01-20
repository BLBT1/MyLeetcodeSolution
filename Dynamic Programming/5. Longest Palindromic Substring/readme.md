# 5. Longest Palindromic Substring

### 解法1： 区间型dp
看到这个题目是最长回文， 就要想到用区间型dp。 我们看个例子：
```
    s = a b a b a a
        0 1 2 3 4 5
```
例子中的最长回文是 "bab" 也就是 s[0:4]， 那给你个 s[0:4]， 你怎么知道他是不是回文呢？我们就要思考他的子问题，```也就是 s[1:3]是不是回文，同时 s[0] 是不是 等于 s[4]```。 到了这里我们就会发现区间型dp的特征了！ 
那就是： ```大区间的最优解，可以依赖小区间的最优解```

那我们怎么定义dp那？有冲动直接定义成题目要的子问题，也就是
```
# this is wrong!
dp[i][j] <- longest palindromic substring of s[i:j]
```
这样定义，更新很麻烦，最后也没办法返回一个substring。这道题的定义应该是：
```
dp[i][j] <- s[i:j]是否是一个回文
```
那么状态转移方程也明了了:
```cpp
 dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
```
最后因需要返回最长的substring： 我们可以使用：
```cpp
        int res = 1;
        pair<int, int> ans = {0, 0};
```
来实时更新，最后返回：
```cpp
        return s.substr(ans.first, ans.second - ans.first + 1);
```
#### Time
    O(N^2)
#### space
    O(N^2)

### 解法2：Manacher's algorithm(马拉车)
https://segmentfault.com/a/1190000003914228

（博主懒了 = =）
#### Time
O(N)
#### Space
O(N)
