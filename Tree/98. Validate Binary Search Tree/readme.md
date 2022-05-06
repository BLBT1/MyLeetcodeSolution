# 98. Validate Binary Search Tree

方法1

- O(N^2)

- 对于每个点，找到左边最大点，再找到右边最小点

- 与当前点对比

```cpp
    bool isValidBST(TreeNode* root) 
    {    
        if(root == nullptr)
            return true;
        
        bool isValid = true;
        if(root->right && minElt(root->right) <= root->val)
            isValid = false;
        if(root->left && maxElt(root->left) >= root->val)
            isValid = false;
        
        return isValidBST(root->left) && isValidBST(root->right) && isValid;     
    }
```

方法2

- O(N)

- bst 有两个法宝 1. inorder traversal 排序， 2. pass down range。 这里要pass down range

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValid(TreeNode* root, long lower, long upper)
    {
        if(root == nullptr)
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;
        return isValid(root->left, lower, root->val) &&
            isValid(root->right, root->val, upper);
    }
};
```
