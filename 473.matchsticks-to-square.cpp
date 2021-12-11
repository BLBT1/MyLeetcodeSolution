/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution
{
    int total = 0;

public:
    bool makesquare(vector<int> &matchsticks)
    {
        // more general: partition in k equ sum subsets
        // we add stick one by one group by one group
        total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0)
            return false;

        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end()); // greedy

        vector<bool> visited(15, false); // at max 15 sticks
        return dfs(matchsticks, visited, 0, 0, 0);
    }

    bool dfs(vector<int> &matchsticks, vector<bool> &visited,
             int curr, int currGrp, int currGrpSum)
    {
        if (currGrp == 4)
            return true;
        if (currGrpSum > total / 4)
            return false;
        if (currGrpSum == total / 4)
            return dfs(matchsticks, visited, 0, currGrp + 1, 0);

        for (int i = curr; i < matchsticks.size(); ++i)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            if (dfs(matchsticks, visited,
                    i + 1, currGrp,
                    currGrpSum + matchsticks[i]))
                return true;
            visited[i] = false;
        } //for

        return false;
    }
};
// @lc code=end
