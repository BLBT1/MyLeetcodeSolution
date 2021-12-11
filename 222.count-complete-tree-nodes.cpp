/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        // setup a bound for binary search
        //* 2^(h-1) ~ 2^h-1
        // find h
        int h = 0;
        TreeNode *ptr = root;
        while (ptr)
        {
            ++h;
            ptr = ptr->left;
        }

        int lo = pow(2, h - 1);
        int hi = pow(2, h) - 1;
        int mid;

        while (lo < hi)
        {
            mid = lo + (hi - lo + 1) / 2;
            bool hasKEle = hasK(root, mid);
            if (hasKEle)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }

    // for this problem, it is very important ot use the special attributes of complete binary tree
    // imagine the tree as indexed by position 1,2,3,4...
    // then for any node, its left child is (node->idx) * 2,
    //                    its right child is (node->idx) *2 + 1
    //* given treeRoot and int k, return if the tree has k nodes
    bool hasK(TreeNode *root, int k)
    {
        // from k to root
        vector<int> path;
        while (k > 0)
        {
            path.push_back(k);
            k /= 2;
        }

        // reverselly treverse
        for (int i = path.size() - 1; i >= 0; --i)
        {
            if (!root)
            {
                return false;
            }

            if (i == 0)
                return true;

            if (path[i - 1] == 2 * path[i])
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return false;
    }
};
// @lc code=end
//      1
//   2    3
// 4  5  6  7
//
// 4 ~ 7
//  mid  = 5
// low = 6 hight = 7
// mid = 6
// 7+7/2
//[6,3,1]
//[7,3,1]