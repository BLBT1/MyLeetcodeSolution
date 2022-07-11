# 785. Is Graph Bipartite

- 首先需要了解bipartite 的定义：　一个图可以把nodes 分成两组，使得所有的 edge 两头的node来自与不同的组

- 所以我们可以从定义出发，用 bfs 层序遍历，并且对比是不是和上层的点在不同的组。

- 一旦发现矛盾， 图就不符合要求
