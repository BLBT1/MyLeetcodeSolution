/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
    struct TrieNode
    {
        TrieNode *next[26];
        bool isEnd = false;

        // contructor
        TrieNode()
        {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };

    TrieNode *root;

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        //* given a dict -> trie
        //* dfs + memo

        // first, construct trie
        root = new TrieNode();

        for (auto &word : wordDict)
        {
            TrieNode *node = root;
            for (auto ch : word)
            {
                if (node->next[ch - 'a'] == nullptr)
                    node->next[ch - 'a'] = new TrieNode();
                node = node->next[ch - 'a'];
            }
            node->isEnd = true;
        } //for

        TrieNode *node = root;

        //* use memo to record where we got wrong
        vector<bool> failed(s.size() + 1, false);

        return dfs(0, s, failed);
    }

    bool dfs(int curr, string &s, vector<bool> &failed)
    {
        if (failed[curr])
            return false;

        // at the end, then we are good
        if (curr == s.size())
            return true;

        TrieNode *node = root;

        for (int i = curr; i < s.size(); ++i)
        {
            if (node->next[s[i] - 'a'] != nullptr)
            {
                node = node->next[s[i] - 'a'];
                if (node->isEnd && dfs(i + 1, s, failed))
                    return true;
            }
            else
            {
                failed[curr] = true;
                break;
            }
        }

        return false;
    }
};
// @lc code=end
