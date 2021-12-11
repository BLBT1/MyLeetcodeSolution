/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
class StreamChecker
{
    // 此题对ood也是很好的考察
    struct TrieNode
    {
        bool isEnd;
        TrieNode *next[26];

        //constructor
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; ++i)
            {
                next[i] = nullptr;
            }
        }
    };

    TrieNode *root;
    string curr;

public:
    StreamChecker(vector<string> &words)
    {
        // construct the trie
        root = new TrieNode();
        for (auto &str : words)
        {
            addWord(str);
        }
    }

    bool query(char letter)
    {
        curr.push_back(letter);
        return find();
    }

    void addWord(string &str)
    {
        // add word from the back to the front
        TrieNode *ptr = root;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            char ch = str[i];
            if (ptr->next[ch - 'a'] == nullptr)
            {
                ptr->next[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->next[ch - 'a'];
        }
        ptr->isEnd = true;
    }

    // find from back to front if curr is in the trie
    bool find()
    {
        TrieNode *ptr = root;
        int i = curr.size() - 1;
        while (i >= 0)
        {
            char ch = curr[i];
            if (ptr->next[ch - 'a'])
            {
                ptr = ptr->next[ch - 'a'];
                if (ptr->isEnd)
                {
                    return true;
                }
                --i;
            }
            else
                break;
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
