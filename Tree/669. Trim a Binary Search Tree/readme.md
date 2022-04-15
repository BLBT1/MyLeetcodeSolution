# 669. Trim a Binary Search Tree

- 使用bst的特性

- 如果当前的点小于 low，那说明当前的点的左子树所有点都小于 low， 只需要在 右子树继续做 trim

- 如果当前点大于 high， 那说明当前是右子树所有点都大于 high， 所以只需要在 左子树继续trim就可以
