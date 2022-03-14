/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l])
            {
                // mid is at the higher part
                if (nums[l] <= target && target <= nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                // mid is at the lower part
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
        }
        // cout << l << " " << r << endl;
        if (l == r && nums[l] == target)
        {
            return l;
        }
        return -1;
    }
};
// @lc code=end

// 0
//  0 1 2 3 4 5 6
// [4 5 6 7 0 1 2]
// [4 5 6 7]
//         [0 1 2]
//        l
//               r
// mid = 3
// mid = 4