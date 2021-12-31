# 1306. Jump Game III

这个题一看就是典型的搜索模板题， dfs 和 bfs 都可以解，用dfs更容易打印出路径。需要一个array记录所以visited过的点，不然就会死循环了。 

### Time
O(N), Each element from input array is only visited once.

### Space
O(N), required for recursive stack