/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (root == NULL)
            return "#";

        string res = to_string(root->val) + "," + to_string(root->children.size()) + ",";

        for (int i = 0; i < root->children.size(); i++)
            res += serialize(root->children[i]) + ",";
        res.pop_back();

        return res;
    }

    // Decodes your encoded data to tree.
    // 3,  4, 5, 5 ...
    // val nc
    Node *deserialize(string data)
    {
        queue<pair<Node *, int>> q;
        for (int i = 0; i < data.size(); ++i)
        {
            int j = i;
            while (j < data.size() && data[j] != ',')
                j++;
            string val_str = data.substr(i, j - i);
            int z = j;
            if (val_str == "#")
                q.push({nullptr, 0});
            else
            {
                z++;
                j++;
                while (z < data.size() && data[z] != ',')
                    z++;
                string num_str = data.substr(j, z - j);
                q.push({new Node(stoi(val_str)), stoi(num_str)});
            }
            i = z;
        }
        return dfs(q);
    }

    Node *dfs(queue<pair<Node *, int>> &q)
    {
        auto root = q.front().first;
        auto numChild = q.front().second;
        q.pop();
        if (root == nullptr)
            return nullptr;

        for (int i = 0; i < numChild; ++i)
        {
            root->children.push_back(dfs(q));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));