# 517. Super Washing Machines

- 这个题的贪心思想是: 如果有两个数据结构记录 machine[i] 向左右 移的个数，left[i] 和 right[i], 那我们希望总是从高处往低处移动。 这样最多填平所需要的move就是最高点所需要往外移动的次数

- 同时我们可以推算出两个关系：
    1. left[i] + right[i] = machine[i] - avg
    2. left[i] = -right[i-1]
