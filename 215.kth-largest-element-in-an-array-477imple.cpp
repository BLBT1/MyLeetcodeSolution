/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        //* try out the QuickSelect
        //* this implementation literally
        //* copy from the 477 lec with a slight modification
        //* this is very slow
        if (nums.size() == 1)
            return nums[0];

        int pivot = nums[0]; // randomly select a num
        //cout << pivot<<endl;
        vector<int> left;  // # > pivot
        vector<int> right; // # <= pivot

        // rank pivot
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > pivot)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        } // for

        if (left.size() == k - 1)
            return pivot;
        else if (left.size() > k - 1)
            return findKthLargest(left, k);
        else
            return findKthLargest(right, k - left.size() - 1);
    }
};
// @lc code=end
