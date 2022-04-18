# 250. Count Univalue Subtrees

- postorder traversal

- 如果左子树和右子树都是 univalue， 那他们再判断当前root的值是不是和左右子树一致

- 因为左子树和右子树都已经 univalue了，所以只需要看左子树右子树的root的值了， 不需要再用helper完全遍历了
