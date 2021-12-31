# 563. Binary Tree Tilt

这个题是个树的题，肯定需要think recursively，想想四种traversal中要用哪个。那我们先考虑root， root 的 tilt 按照定义就是 ```左子树和 - 右子树和```， 那怎么找到他的左子树和和右子树和呢？ 那就是recursively 先找到他的左子树的左子树和和右子树和 + 他左子树的值， 以及 他的右子树的左子树和 和右子树和 + 他右子树的值。 所以为了达到这个目的，我们需要用 ```Post Order Traversal```

```cpp
    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftSum = postOrder(root->left);
        int rightSum = postOrder(root->right);
        return rightSum + leftSum + root->val;
    }
```

同时， 在post order 的过程中可以顺便算出并加上各个点的tilt：

```cpp
        res += abs(rightSum - leftSum);
```


## time complexity： 
树的每个点都访问了 所以是O(N)
## space complexity:
O(H), H 是recursive stack 的大小. 
- 如果树一边倒, 为 O(N)
- 如果balanced tree, 为 O(logN)