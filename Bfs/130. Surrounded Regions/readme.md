# 130. Surrounded Regions

逆向思维，如果要flip所有包围的岛屿， 那其实可以找到所有没被包围的岛， 也就是靠边界的岛，我们可以找到他们并且标记。所以只需要对边界的点进行bfs就可以