# 394. Decode String

- 两个stack， 一个存次数， 一个存内容， 看到 [ 说明开始新的层级， 看到 ] 说明当前层级结束，要从times 里 乘倍， 并且append到栈顶元素， 存为curr

- 思路和 224 calculator 非常相似

- time: O(N*k), k is avg number of time

- space: O(N)
