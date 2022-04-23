# 105. Construct Binary Tree from Preorder and Inorder Traversal

1. preorder 的第一个肯定是 root的位置

2. 在 inorder里找到 root的值所对应的index， 这样 通过这个index， 我们可以在 inorder里找到 root的左子树的范围 和 inorder 里右子树的范围

3. 再通过这个两个范围， 回到 preorder 找到：
    - 左子树的头： root+1

    - 右子树的root： root+左子树的node的个数 + 1

4. 通过左子树的root和左子树的root的范围，右子树的root和右子树的范围， recursively 解决问题

5. base case就是：
    - root 超出了preorder 的界限

    - node范围为空 (in_end < in_beg)
