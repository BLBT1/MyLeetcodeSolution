# 437. Path Sum III

先思考 如果必须从root出发， 那有几种可能的 pathSum, 改怎么写

```cpp
    int pathSumRoot(TreeNode *root, int targetSum)
    {
        if(root == nullptr) return 0;
        int res = 0;
        if(root->val == targetSum)
            res += 1;

        res += pathSum(root->left, targetSum - root->val);
        res += pathSum(root->right, targetSum - root->val)

        return res;
    }
```

然后，我们就可以把tree 里所有的点都当作 root 来思考

```cpp
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        return helper(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }

```

Time complexity: O(N^2)
