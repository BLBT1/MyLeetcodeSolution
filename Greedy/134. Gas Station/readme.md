# 134. Gas Station

非常奇特的算法

1. 如果无法走完全程， 那一定是把所有的cost相加大于所有的gas相加

2. 假设我们从A开始走，走到C了，发现到达不了。那C就是第一个无法到达的点。 那AC之间所有的点都不可能到达C，也就是都不可能走完。所有下一个尝试的开始点就是C+1
