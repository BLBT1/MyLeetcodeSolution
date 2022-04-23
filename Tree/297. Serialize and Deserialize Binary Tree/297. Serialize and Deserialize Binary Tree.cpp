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
        // use preorder traversal
        // use # for nullptr
        if (root == nullptr)
            return "#";
        // use , for seperators
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // vector to store all nodes
        queue<TreeNode *> nodes;

        for (int i = 0; i < data.size(); ++i)
        {
            // find the next number
            int j = i;
            while (j < data.size() && data[j] != ',')
                j++;
            string str = data.substr(i, j - i);

            if (str == "#")
                nodes.push(nullptr);
            else
                nodes.push(new TreeNode(stoi(str)));
            i = j;
            // i now is on ","
        }

        return dfs(nodes);
    }

    TreeNode *dfs(queue<TreeNode *> &q)
    {
        TreeNode *root = q.front();
        q.pop();
        if (root == nullptr)
            return nullptr;
        root->left = dfs(q);
        root->right = dfs(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));