# 490. The Maze

- 这题目是典型的bfs模板题

- 没有遇到墙壁就要一直往下走

```cpp
// if not the wall or out of board, keep going
while(x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && maze[x_][y_] != 1)
{                                    
    x_ = x_ + d.first;
    y_ = y_ + d.second;
}
```
