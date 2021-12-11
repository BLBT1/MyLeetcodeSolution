/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        // stack basic function applys

        stack<pair<int, int>> s;
        vector<int> res(n, 0);
        for (const auto &log : logs)
        {
            int pos1 = log.find(":", 0);
            int pos2 = log.find(":", pos1 + 1);
            int id = stoi(log.substr(0, pos1));
            bool act = (log.substr(pos1 + 1, pos2 - pos1 - 1) == "start");
            int time = stoi(log.substr(pos2 + 1));

            if (act)
            {
                s.push({id, time});
            }
            else
            {
                int start = s.top().second;
                int dur = time - start + 1;
                s.pop();
                res[id] += dur;

                if (!s.empty())
                {
                    int prevId = s.top().first;
                    res[prevId] -= dur;
                }
            }
        } //for

        return res;
    }
};
// @lc code=end
