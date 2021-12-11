/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution
{
    struct TrieNode
    {
        TrieNode *next[26];
        int isEnd = 0;
        TrieNode()
        {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };
    TrieNode *root;
    vector<vector<string>> res;

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // construct tire by the given list
        root = new TrieNode();
        for (auto &s : products)
        {
            TrieNode *node = root;
            for (auto ch : s)
            {
                if (node->next[ch - 'a'] == nullptr)
                {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->isEnd += 1;
        } //end construct trees

        TrieNode *node = root;
        string word;
        for (int i = 0; i < searchWord.size(); i++)
        {
            char ch = searchWord[i];
            if (node->next[ch - 'a'] == nullptr)
            {
                for (int j = i; j < searchWord.size(); j++)
                    res.push_back({});
                break;
            }

            node = node->next[ch - 'a'];
            word.push_back(ch);
            vector<string> list;
            string temp = "";
            dfs(temp, node, list);

            while (list.size() > 3)
                list.pop_back();
            for (int j = 0; j < list.size(); j++)
                list[j] = word + list[j];
            res.push_back(list);
        }

        return res;
    }

    void
    dfs(string curr, TrieNode *node, vector<string> &list)
    {

        if (node == nullptr)
            return;
        if (node->isEnd > 0)
        {
            for (int k = 0; k < node->isEnd && list.size() < 3; k++)
                list.push_back(curr);
        }

        for (int i = 0; i < 26; ++i)
        {
            if (list.size() > 3)
                return;
            if (node->next[i] != nullptr)
            {
                curr.push_back(i + 'a');

                dfs(curr, node->next[i], list);
                curr.pop_back();
            }
        }
    }
};
// @lc code=end
