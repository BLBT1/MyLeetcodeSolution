# 694. Number of Distinct Islands

- 难点是如何标记形状，　可以用我们如何到达岛屿中的每个点的方位来标记每个岛屿的形状，所以要用dfs

- 值得注意的是，用这种方式，　不同的形状可能有相同的 encoding，　列如以下两个图都可能是　srdr

```
 1 1 1     1 1
   1         1 1
```

- 解决这个问题，　我们可以在每次 backtrack 的时候加个ｅ, 这样上面两个图就变成 srder 和　srdre　了。　这样所有的　encoding 都　unique 了
