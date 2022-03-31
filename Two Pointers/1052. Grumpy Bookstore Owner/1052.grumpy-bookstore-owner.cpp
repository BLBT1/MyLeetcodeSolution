/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int base = 0;
        int sum = 0;
        int res = 0;
        // nums of customer happy no matter if the tech is used
        for (int i = 0; i < customers.size(); ++i)
            if (grumpy[i] == 0)
                base += customers[i];

        // sliding window with a fixed size
        for (int j = 0; j < customers.size(); ++j)
        {
            if (grumpy[j] == 1)
            {
                sum += customers[j];
            }
            if (j - minutes >= 0 && grumpy[j - minutes] == 1)
            {
                sum -= customers[j - minutes];
            }
            res = max(res, sum);
        }
        return res + base;
    }
};

// max length with max 0s -> length with max customers
// map{pos}
//

// [0, 1, 0, 1, 0, 1, 0, 1]
//  1  2  3  4  5  6  7  8

// @lc code=end
