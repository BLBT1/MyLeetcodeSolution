# 424. Longest Repeating Character Replacement

方法一

- 因为s中只包含 upper char， 所以我们可以指定每次只替换[A:Z]中的一个，做26次滑动窗口， time就是 O(26N)

方法二

- 用一个set来统计出现过的char，和方法一很接近
