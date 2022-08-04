# 332. Reconstruct Itinerary

dfs里每次我们访问过一条边，我们就把他从图里去掉，当我们访问到终点了，发现图里还有边， 那就定以这个path 为 path i, 那剩下的边肯定可以组成一个 the Eulerian circuit， path j， 那最终点：curr + path i + path j

[guan神具体讲解](https://github.com/wisdompeak/LeetCode/tree/master/DFS/332.Reconstruct-Itinerary)
