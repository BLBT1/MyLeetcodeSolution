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
    TreeNode *str2tree(string s)
    {
        if (s == "")
            return nullptr;

        TreeNode *curr = nullptr;
        stack<TreeNode *> Stack;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                // start build a new tree use the top from stack
                Stack.push(curr);
                curr = nullptr;
            }
            else if (s[i] == ')')
            {
                // add built tree to the top from stack
                if (Stack.top()->left == nullptr)
                    Stack.top()->left = curr;
                else
                    Stack.top()->right = curr;
                curr = Stack.top();
                Stack.pop();
            }
            else
            {
                int j = i;
                while (j < s.size() && s[j] != '(' && s[j] != ')')
                {
                    j++;
                }
                curr = new TreeNode(stoi(s.substr(i, j - i)));
                i = j - 1;
            }
        }

        return curr;
    }
};