# 834. Sum of Distances in Tree

这题最重要的是要找出 f(parent) 与 f(child) 之间的关系。假设 f（x）为 sum of dist(x), 我们可以发现 f(child) = f(parent) + a -b

- a = subtree(child)

- b = n - subtree(child)

- so ```f(child) = f(parent) + n - 2*subtree(child)```

这样，可以通过3次的dfs用 O(N) 的时间来完成此题
