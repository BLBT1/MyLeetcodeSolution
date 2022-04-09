# 25. Reverse Nodes in k-Group

- 先把每个 group 的 list 打断， 并且用 vector 存下每个sublist的头， 这样便于接下里的操作

- 最后如果完整的 sublist，设个flag，接下来不用reverse

- reverse linked list 和 lc206 代码一样

- 最后走一遍把list都重新连起来
