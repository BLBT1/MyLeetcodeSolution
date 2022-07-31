# 696. Count Binary Substrings

给一个　"0001111", 我们怎么知道里面有几个符合调价的　substring？

- 其实就是 min(一个字符的数量，当前字符的数量)

- 所以我们可以用curr记录当前元素连续出现的次数

- 用prev记录上一个元素连续出现的次数

- 每次元素变化的时候　(0->1)/(1->0)，res+= min(prev, cur). 用prev记录curr，设curr为 1

- 最后 for loop 结束了好要做一次
