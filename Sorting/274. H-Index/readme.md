# 274. H-Index

这个题最重要的是理解题意:

A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

所以当我们把所有的数字都sort后， i 从右往左 用 cnt 计数，那就有 cnt 个的 citation >= citation[i]
