/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return bsearch(0, nums.size(), nums, target);
    }

    int bsearch(int left, int right,
                vector<int> &nums, int target)
    {
        //* base case
        if (right <= left)
            return -1;
        // * do bsearchs
        int mid = (right + left) >> 1;
        if (nums[mid] > target)
            return bsearch(left, mid, nums, target);
        else if (nums[mid] < target)
            return bsearch(left + 1, right, nums, target);
        else
            return mid;
    }
};
// @lc code=end
