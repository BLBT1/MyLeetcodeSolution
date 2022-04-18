# 314. Binary Tree Vertical Order Traversal

- col需要基准点，我们可以选root 为 0， 那 root的左孩子为 -1，root的右孩子为 1， 以此类推

- 因为题目要求从高到低， 从左到右 输出， 所有遍历中用 level order traversal 最容易保证这个要求

- 放进q的时候用个pair，把node的所在 col也放进去， {col， TreeNode*}

- 用一个 map 存结果， {col， vector<int>}， 这样可以自动按照 col的顺序排序
