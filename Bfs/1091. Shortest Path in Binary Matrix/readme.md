# 1091. Shortest Path in Binary Matrix

这个题目第一反应想用 dijkstra， 但是其实是不需要的， 因为可以斜着走，所以只需要一层一层向外搜索， 用bfs 就可以了

time: O(MN)
