/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution
{
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    TrieNode *root;
    int memo[300];
    vector<string> res;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        root = new TrieNode();
        for (auto &word : wordDict)
        {
            TrieNode *node = root;
            for (auto ch : word)
            {
                if (node->next[ch - 'a'] == NULL)
                    node->next[ch - 'a'] = new TrieNode();
                node = node->next[ch - 'a'];
            }
            node->isEnd = true;
        }

        vector<string> ans;
        dfs(s, 0, ans);
        return res;
    }

    bool dfs(string &s, int cur, vector<string> &ans)
    {
        if (memo[cur] == 1)
            return false;

        if (cur == s.size())
        {
            string t;
            for (auto word : ans)
                t += word + " ";
            t.pop_back();
            res.push_back(t);
            return true;
        }

        TrieNode *node = root;
        bool flag = false;
        for (int i = cur; i < s.size(); i++)
        {
            if (node->next[s[i] - 'a'] != NULL)
            {
                node = node->next[s[i] - 'a'];
                if (node->isEnd == true)
                {
                    ans.push_back(s.substr(cur, i - cur + 1));
                    if (dfs(s, i + 1, ans))
                        flag = true;
                    ans.pop_back();
                }
            }
            else
            {
                break;
            }
        }

        if (flag == false)
            memo[cur] = 1;
        return flag;
    }
};
// @lc code=end
