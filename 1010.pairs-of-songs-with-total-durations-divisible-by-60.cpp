/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        // inspired by two sum
        // space: O(n*max)
        // time: (n*max)
        unordered_map<int, int> map; // {diff, frq}
        int res = 0;
        int max = 1000 / 60;
        for (int i = 0; i < time.size(); ++i)
        {
            if (map.find(time[i]) != map.end())
                res += map[time[i]];
            for (int j = 1; j <= max; ++j)
            {
                map[j * 60 - time[i]]++;
            }
        }

        return res;
    }
};
// @lc code=end

// time[i] duration of i the song in sec
// return i,j s.t. (time[i] + time[j]) % 60 == 0

//[60, 60, 60] output = 3
// 60 120 ... 1000 / 60 =
// map <diff, frq>
// 480 / 60 == 8
//[60, 1]