# 124. Binary Tree Maximum Path Sum

- 看到这样人字形(非直线) 的 path， 就应该想到 用 postorder traversal，再用一个global跟新 res， 相同的题目还有 ```543. Diameter of Binary Tree```

- postorder traversal tree的recursion题目我们需要问我们自己三个问题

- q1： 我们从左子树，右子树拿到的是什么

- q2： 我们当前node需要做什么

- q3：我们需要往上传递什么

这里回答三个问题：1) 我们拿到的是从左孩子，右孩子出发的直线的最大path sum. 2) 我们当前要把自己看成一个拐点，然后和res对比update 3) 我们需要上传的是以自己出发的直线的最大path sum
