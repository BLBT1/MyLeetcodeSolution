# 938. Range Sum of BST

典型的dfs题，需要注意两点：

1. 需要把 range一起 pass down
2. 如果一个 node 越界了， 但是他的左右孩子还是有可能在range里的， 所以要继续pass down， 直到 nullptr 为止