# 529. Minesweeper

- 要判断所有的相邻的点是不是有地雷， 所以是标准的bfs

- 用cnt记录有几个地雷， 如果是地雷 cnt

- 如果不是地雷， 用next记录下来，最后如果当前cnt 不是 0， 那就需要把next 里的点 push进queue里， 继续处理
