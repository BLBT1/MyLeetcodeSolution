/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(weights, days, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    bool check(vector<int> &weights, int day, int cap)
    {
        int cnt = 0;
        for (int i = 0; i < weights.size(); ++i)
        {
            int j = i;
            int sum = 0;
            while (j < weights.size() && sum + weights[j] <= cap)
            {
                sum += weights[j];
                j++;
            }
            i = j - 1;
            cnt++;
        }
        return cnt <= day;
    }
};
// @lc code=end
