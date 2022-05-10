# 236. Lowest Common Ancestor of a Binary Tree

- 用postorder traversal， 因为 每个点需要他leaves 的信息

- 如果左子树和右子树都不为空，那当前root 一定就是 lca

- 如果找到 p 或 q， 那就返回他们

- 不然就返回 nullptr
