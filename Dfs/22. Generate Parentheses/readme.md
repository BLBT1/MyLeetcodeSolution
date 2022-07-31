# 22. Generate Parentheses

- left <- 已经加的 (

- right <- 已经加的 )

- 左括号必须比右括号先加

- 当目前左括号的个数多余右括号的时候， 我们才能加右括号

## Time

f(n) = g(n) *h(n) where g(n) is the time complexity for calculating nth catalan number, and h(n) is the time required to copy this combination to result array.
Therefore, f(n) = catalan(n)* O(n) which is O(4^n/n^1.5)*(n))

[See this post](https://leetcode.com/problems/generate-parentheses/discuss/10099/Time-complexity-to-generate-all-combinations-of-well-formed-parentheses.)
