/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        // greedy
        if (startFuel >= target)
            return 0;

        int currSta = 0;
        int currFuel = startFuel;
        int res = 0;
        priority_queue<int> pq;

        stations.push_back({target, 0});

        while (currSta < stations.size())
        {
            if (currFuel >= stations[currSta][0])
            {
                //store the fuel of stations we have passed
                pq.push(stations[currSta][1]);
                currSta++;
            }
            else
            {
                while (currFuel < stations[currSta][0] && pq.size() > 0)
                {
                    currFuel += pq.top();
                    pq.pop();
                    res += 1;
                }

                if (currFuel < stations[currSta][0] && pq.size() == 0)
                    return -1;
            }
        }

        return res;
    }
};
// @lc code=end
