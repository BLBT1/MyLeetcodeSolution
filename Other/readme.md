# 59. Spiral Matrix II

- 从外向内一圈一圈的填

- 锁定上下左右的边界

- 以下顺序对4个方向进行填写

    1. 从左到右，[left -> right]

    2. 从上到下, [up+1 -> down]

    3. 从右到左 [right-1 -> left]

    4. 从下到上 [down-1 -> up+1]
