# 297. Serialize and Deserialize Binary Tree

- serialize 和 deserialize 的本质是把树parse 成一个string 便于传输， 再从string复原

- serialzie很简单， 用 "#" 表示 nullptr，用 "," 分离树的每个点， 做 preorder

- 为什么用 preorder 最好？ 因为 preorder traversal 有是遍历中唯一能 复原唯一二叉树的：
    1.第一个 node 一定是 root
    2. 第二个node 一定是左子树的 root

dfs(1)
1, {2,#,#}, {3,4,#,#,5,#,#}

dfs(2)   dfs(3)
{2,#,#}, {3,4,#,#,5,#,#}
              dfs(4)  dfs(5)
        {[3],[4,#,#],[5,#,#]}

Reason: 
    1. the first element is always the root
    2. we can recursively solve the sub problem by calling dfs on the second element 
        - **because we can know the left child tree size after construct it, so that we know the root of rigt child tree**

- 这个题的难点是如何 deserialize
  - 先处理 string 使每个node都存在一个 queue里
  - 再用 queue 做 dfs， 一边pop， 一边构建树


Time(O(N)) -> because we do additional traversal for getting tree size
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // use # for null pointer
        // use preorder traversal
        return preorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // store all nodes for construct the tree
        int i = 0;
        vector<TreeNode*> nodes;
        while(i < data.size()){
            int j = i;
            while (j < data.size() && data[j] != ',') ++j;
            string s = data.substr(i, j-i);
            if(s == "#") {
                nodes.push_back(nullptr);
            } else{   
                int currVal = stoi(s);
                nodes.push_back(new TreeNode(currVal));
            }
            i = j+1;
        }

        return construct(nodes, 0);
    }

    // curr is the curr idx in the nodes that we are taking as root
    TreeNode* construct(vector<TreeNode*> nodes, int curr){
        if(nodes[curr] == nullptr)
            return nullptr;

        TreeNode* leftTree = construct(nodes, curr+1);
        int leftsize = getSize(leftTree);
        TreeNode* rightTree = construct(nodes, curr+1+leftsize);
        nodes[curr]->left = leftTree;
        nodes[curr]->right= rightTree;
        return nodes[curr];
    }

    string preorder(TreeNode* root){
        if(root == nullptr)
            return "#";

        string leftEncode = preorder(root->left);
        string rightEncode = preorder(root->right);

        return to_string(root->val) + "," + leftEncode + "," + rightEncode;
    }

    int getSize(TreeNode* curr){
        if (curr == nullptr) return 1; // because nullptr takes space in nodes
        return 1+ getSize(curr->left)+getSize(curr->right);
    }
};
```

## Optimize: store nodes in queue instead of vector, so we can pop instead of calculate left child tree size
Time O(N)

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {    
        // use preorder traversal
        // use # for nullptr
        if(root == nullptr)
            return "#";
        // use , for seperators
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {    
        // vector to store all nodes
        queue<TreeNode*> nodes;
        
        for (int i=0; i<data.size(); ++i)
        {
            // find the next number
            int j = i;
            while (j<data.size() && data[j]!=',')
                j++;
            string str = data.substr(i,j-i);
            
            if (str=="#")
                nodes.push(nullptr);
            else
                nodes.push(new TreeNode(stoi(str)));
            i = j;
            // i now is on ","
        }

        return dfs(nodes);
    }
    
    TreeNode* dfs(queue<TreeNode*> &q)
    {
        TreeNode* root = q.front();
        q.pop();
        if(root == nullptr)
            return nullptr;
        root->left = dfs(q);
        root->right = dfs(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```


