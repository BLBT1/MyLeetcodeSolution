/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 双向dfs
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;

        const int len = beginWord.size();
        int step = 1;

        // one from begin, one from end
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};

        while (!q1.empty() && !q2.empty())
        {
            ++step;
            //* 这一步是核心优化
            //* 交替扩展头尾，但是优先拓展短的
            if (q1.size() > q1.size())
                swap(q1, q2);

            unordered_set<string> next;

            for (auto w : q1)
            {
                for (int i = 0; i < w.size(); ++i)
                {
                    char orig = w[i];
                    for (char letter = 'a'; letter <= 'z'; ++letter)
                    {
                        if (letter != orig)
                        {
                            w[i] = letter;
                            if (q2.find(w) != q2.end())
                                return step;

                            if (dict.find(w) != dict.end())
                            {
                                dict.erase(w);
                                next.insert(w);
                            } //if
                        }
                    }            //for change letter
                    w[i] = orig; // change back to orig to ready for change next pos in word
                }                //for each pos in that word
            }                    //for treversal all words in q1

            swap(next, q1);
        } //while

        return 0;
    }
};
// @lc code=end
