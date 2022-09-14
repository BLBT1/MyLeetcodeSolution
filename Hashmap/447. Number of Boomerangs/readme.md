# 447. Number of Boomerangs

如果 dist(a,c) == dist(b,c), 那我们就可以以c 为第三点， 有两种可能。如果包含c的edge有 k 个相同长度的， 那我们用可以有 k*(k-1) 种

遍历所有可能的 c， 就是结果
