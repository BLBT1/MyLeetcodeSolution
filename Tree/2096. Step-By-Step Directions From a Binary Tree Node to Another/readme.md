# 2096. Step-By-Step Directions From a Binary Tree Node to Another

找最短路径，就应该想到是要找 LCA。 那LCA怎么找？一种传统的recurion方法是用post order traversal 判断是否遇到了p和q。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 需要把下面节点的信息往上传
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left != nullptr && right != nullptr)
            return root;
        
        if(left != nullptr)
            return left;
        
        if(right != nullptr)
            return right;
        
        return nullptr;
    }
};
```

这里同理，居然要答应路径， 那我们就用 dfs 标记路径。然后再对比root 到 start 和 dest的路径。 找到一个不同的位置k。反转path1中k到start的， 最后拼接路径。
