# 297. Serialize and Deserialize Binary Tree

- serialize 和 deserialize 的本质是把树parse 成一个string 便于传输， 再从string复原

- serialzie很简单， 用 "#" 表示 nullptr，用 "," 分离树的每个点， 做 preorder

- 为什么用 preorder 最好？ 因为 preorder traversal 有是遍历中唯一能 复原唯一二叉树的：
    1.第一个 node 一定是 root
    2. 第二个node 一定是左子树的 root

- 这个题的难点是如何 deserialize

  - 先处理 string 使每个node都存在一个 queue里

  - 再用 queue 做 dfs， 一边pop， 一边构建树

  - 这个方法很巧妙， 值得熟练记忆！
