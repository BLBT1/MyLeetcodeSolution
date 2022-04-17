# 958. Check Completeness of a Binary Tree

## 解法一： 传统解法

如果从上到下，从左到右，从0开始标号，那

- left index = parent index *2 +1
- right index = parent index* 2 +2.

我们可以根据这个， 先找到总共右几个node，再用上面的规律判断左孩子和有孩子的位置。 ```任何非完全二叉树，按照上述规则编号，则必然会导致有某个节点的编号大于了总节点数目。```

## 解法二： level order traversal

层次遍历，遇到nullptr了就停下。之后再看 queue里留下的点里是不是还有 非 nullptr的点
