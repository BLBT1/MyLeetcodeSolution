/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> cnt1(n + 1, 0); // {people who trust i}
        vector<int> cnt2(n + 1, 0); // {i trust who}

        if (trust.empty())
            return (n == 1) ? 1 : -1;

        //unordered_set total;
        for (auto &tru : trust)
        {
            cnt1[tru[1]]++;
            cnt2[tru[0]]++;
        }

        for (int i = 0; i < cnt1.size(); ++i)
        {
            if (cnt1[i] == n - 1 && cnt2[i] == 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end
