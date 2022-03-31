/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        queue<int> q; //  position where 0 being flipped
        int l = 0, r = 0;
        int res = 0;
        for (; r < nums.size(); ++r)
        {
            if (nums[r] == 0)
            {
                q.push(r);
            }
            if (q.size() > k)
            {
                l = q.front() + 1;
                q.pop();
            }
            res = max(r - l + 1, res);
        }
        return res;
    }
};
// res 6
// k = 2
//  0 1 2 3 4 5 6 7 8 9 10
// [1,1,1,0,0,0,1,1,1,1,0]
//          l
//                      r
// q {4}
// @lc code=end
