# 96. Unique Binary Search Trees

- 假设 n = 4，func = numBST（4），那[1:4] 每个node都可能是 root，
  - 如果 1 是 root
    - 那左边就可以放 0 个， 右边可以放 3 (4-1, 1 is root)个点
    - 那 以 1 为 root， 就可能组成 numBST(0) * numBST(3) = 5

  - 如果 2 是root， 那 就是 numBST(1) * numsBST(2) = 2

  - 如果 3 是root， 那 就是 numBST(2) * numsBST(1) = 2

  - 如果 4 是root， 那 就是 numBST(3) * numsBST(0) = 5
- 所以 numBST(4) = 14

- 那 假设 n 个 node

  - numBST(n) = sum for j from 1 to n (每个点都可以是root)，

    - 那 j 左边有 j-1 个 node for 左子树
    - j 的右边有 n-1-j 个 node for 右子树
