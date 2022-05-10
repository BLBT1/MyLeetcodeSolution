# 1644. Lowest Common Ancestor of a Binary Tree II

q 或 p 可能不存在， 所以可以用一个 counter 记录以下， 遇到 p 或 q 就 ++， 如果 cnt 不是 2， 就返回 nullptr
