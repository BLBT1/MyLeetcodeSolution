/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<TreeNode *> q;
        for (int i = 0; i < data.size(); ++i)
        {
            int j = i;
            while (j < data.size() && data[j] != ',')
            {
                ++j;
            }
            string num_str = data.substr(i, j - i);
            q.push(new TreeNode(stoi(num_str)));
            i = j;
        }

        return dfs(q, INT_MAX, INT_MIN);
    }

    // pass down the upper bound and lower bound for bst
    TreeNode *dfs(queue<TreeNode *> &q, int upper, int lower)
    {
        if (q.empty())
            return nullptr;
        TreeNode *root = q.front();
        if (root->val < lower || root->val > upper)
            return nullptr;
        q.pop();

        root->left = dfs(q, root->val, lower);
        root->right = dfs(q, upper, root->val);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;