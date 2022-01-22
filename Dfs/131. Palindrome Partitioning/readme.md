# 131. Palindrome Partitioning

这个题第一反应就是要用dfs， 因为需要给出所有可能的partition, 但是怎么判断 s[i:j] 是不是一个回文呢？native太慢了！！！ 这里就想到了```lc5```的做法1， 用区间型dp提前记录 s[i:j] 是否是回文即可

Time:
O(2^n), as given a set with n element, it has 2^n subsets

Space:
O(n^2), dp