/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // fast-slow ptr
        // very hard to think of
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } //while

        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

// nums = [ 1, 3, 4, 2, 2 ] n+1 numbers in range [1,n]
// output = 2
