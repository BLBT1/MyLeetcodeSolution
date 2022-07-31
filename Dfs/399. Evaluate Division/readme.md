# 399. Evaluate Division

这个题其实是可以转化成一个graph的题目

- 比如说： a/b = 2, b/c = 3, 那 a/c 其实是 (a/b)*(b/c) = 2.3 = 6

- 可以转化为图： a-> = a->b->c

- 图中可能有分叉：

```
             ->b->d
            a->c->e
             ->g->w
```

此图中我们想找到　a/z，　也就是 a->z 的　路径，　那就需要用dfs

Time: O(E+E*Q), E is number of equation, Q is number of queries
