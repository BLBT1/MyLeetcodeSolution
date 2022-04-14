# 543. Diameter of Binary Tree

## Brute force

遍历所有的点，把每个点都当作root做 bfs，记录最长的path，O(N^2)

## Better

思考每个点作为拐点， 那穿过当前拐点的最长路径就是他左他的左高度+他的右高度，我们可以递归完成，并且记录更新结果，这种解法是 O(N)

- 注意diameter 不一定经过 root

- 返回是 num of edges， 不是 num of nodes
