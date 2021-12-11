/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

class Solution
{
    //* still quicksort
    //* but use 3 ptr method to improve the partition process
    //* this 3 ptr method is inspired from lc 075
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickselect(nums, 0, nums.size() - 1, k);
    }

    int quickselect(vector<int> &nums, int begin, int end, int k)
    {
        int pivot = nums[(begin + end) / 2];

        int i = begin, j = end;
        int t = begin;
        while (t <= j)
        {
            if (nums[t] < pivot)
            {
                swap(nums[i], nums[t]);
                i++;
                t++;
            }
            else if (nums[t] > pivot)
            {
                swap(nums[j], nums[t]);
                j--;
            }
            else
                t++;
        }

        if (end - j >= k)
            return quickselect(nums, j + 1, end, k);
        else if (end - i + 1 >= k)
            return pivot;
        else
            return quickselect(nums, begin, i - 1, k - (end - i + 1));
    }
};

// @lc code=end
