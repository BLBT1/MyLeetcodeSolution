/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution
{
    vector<string> res;

public:
    vector<string> addOperators(string num, int target)
    {
        // 这题很多细节
        string currExp = "";
        long long currRes = 0;
        int curr = 0;
        dfs(num, target, curr, currRes, currExp, currRes);
        return res;
    }

    void dfs(string &num, int target, int curr,
             long long currRes, string currExp, long long lastTerm)
    {
        if (curr == num.size())
        {
            if (currRes == target)
                res.push_back(currExp);
            return;
        }

        for (int i = curr; i < num.size(); ++i)
        {
            string currNumS = num.substr(curr, i - curr + 1);
            if (currNumS.size() > 1 && currNumS[0] == '0')
                continue;

            long long currNum = stoll(currNumS);

            if (curr == 0)
                dfs(num, target, curr + currNumS.size(),
                    currRes + currNum,
                    currExp + currNumS, currNum);
            else
            {
                dfs(num, target, curr + currNumS.size(),
                    currRes + currNum,
                    currExp + "+" + currNumS, currNum);
                dfs(num, target, curr + currNumS.size(),
                    currRes - currNum,
                    currExp + "-" + currNumS, -currNum); //notice, turn to minus
                dfs(num, target, curr + currNumS.size(),
                    currRes - lastTerm + lastTerm * currNum,
                    currExp + "*" + currNumS, lastTerm * currNum);
            }
        }
    } //dfs()
};
// @lc code=end

//123 + 4 * dfs(...)

//