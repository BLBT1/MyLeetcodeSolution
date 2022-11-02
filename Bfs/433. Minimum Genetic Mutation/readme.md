# 433. Minimum Genetic Mutation

和word ladder 很相似的题， 看到给一个start 给一个 end， 找中间的最短距离， 每次只能mutate 一个， 这就是明显的 BFS

给了bank，注意bank的数据规模不大， 所以每次搜索时， 只需要看bank里有没有包含 与当前string只相差1 的string， 这些都可以加进queue里面去
