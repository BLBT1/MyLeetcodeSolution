/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 1)
            return findkthSortedArrays(nums1, 0, nums2, 0, (m + n) / 2 + 1);
        else
            return (findkthSortedArrays(nums1, 0, nums2, 0, (m + n) / 2) + findkthSortedArrays(nums1, 0, nums2, 0, (m + n) / 2 + 1)) * 1.0 / 2;
    }

    // generalized the problem into a more common problem
    int findkthSortedArrays(vector<int> &nums1, int nums1Start,
                            vector<int> &nums2, int nums2Start,
                            int k)
    {
        // idea:
        //nums1: X0 XX X_ XXX
        //nums2: Y0 YY Y_ YYYYYY
        // if X_ < Y_ then,
        // X0 to X_ AND Y0 to prev(Y_) are not possible for kth smallest element,
        // so we can remove all the element int range [X0: X_]
        // we can recursively doing this procedure until (base case)
        // 1. k == 1
        // 2. one array turn to be empty
        int m = nums1.size();
        int n = nums2.size();

        // invariant: m <= n
        if (m - nums1Start > n - nums2Start)
            return findkthSortedArrays(nums2, nums2Start, nums1, nums1Start, k);

        // handle two base case
        if (nums1Start == m)
            return nums2[nums2Start + k - 1];
        if (k == 1)
            return min(nums1[nums1Start], nums2[nums2Start]);

        int x_, y_;
        if (nums1Start + k / 2 >= m)
            x_ = m - nums1Start;
        else
            x_ = k / 2;
        y_ = k - x_; // so that y_+x_ = k

        if (nums1[nums1Start + x_ - 1] < nums2[nums2Start + y_ - 1])
            return findkthSortedArrays(nums1, nums1Start + x_, nums2, nums2Start, k - x_);
        else
            return findkthSortedArrays(nums1, nums1Start, nums2, nums2Start + y_, k - y_);
    }
};

// @lc code=end
