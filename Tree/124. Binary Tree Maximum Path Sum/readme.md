# 124. Binary Tree Maximum Path Sum

- 看到这样人字形(非直线) 的 path， 就应该想到 用 postorder traversal，再用一个global跟新 res， 相同的题目还有 ```543. Diameter of Binary Tree```

- postorder traversal tree的recursion题目我们需要问我们自己三个问题

- q1： 我们从左子树，右子树拿到的是什么

- q2： 我们当前node需要做什么

- q3：我们需要往上传递什么

- 这里回答三个问题：1) 我们拿到的是从左孩子，右孩子出发的直线的最大path sum. 2) 我们当前要把自己看成一个拐点，然后和res对比update 3) 我们需要上传的是以自己出发的直线的最大path sum

- 这个题最那想到的地方是： 一个单独的点也可能是一个path，那如果左右两个孩子的 pathsum 是负数， 那还不如不加他们， 所有如果看到他们小于0，可以直接设他们为0

## 二刷体验

这道题目要注意两个点：

1. 需要返回的是path sum， 所以leftSum 和 rightSum 中只挑选一个大的返回
2. 此题最核心的思想： 果左右两个孩子的 pathsum 是负数， 那还不如不加他们， 就我自己root单独一个点就是最大的。所以说每次拿到左右孩子的 path sum的时候都要和0对比一下:

```cpp
        int leftSum = max(getPosSum(root->left), 0);
        int rightSum = max(getPosSum(root->right), 0);
```
