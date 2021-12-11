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
        /*
        * idea:
        * find a point in num1 and a point in nums2 to partition two array into left and right 2 parts
        * s.t. the nums of element in the left is >= num of element in the right
        * and also
        * the X_Left_max <= Y_right_min and Y_left_max <= X_right_min
        * 
        * We do a binary search on the short array to find such partition
        */
        const int m = nums1.size();
        const int n = nums2.size();

        //* make sure to do partition on the shorter array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        const int numLeft = (m + n + 1) >> 1;

        int l = 0, r = m;
        while (l < r)
        {
            int partX = (l + r) >> 1;
            int partY = numLeft - partX;
            if (nums1[partX] < nums2[partY - 1])
            {
                l = partX + 1;
            }
            else
            {
                r = partX;
            }
        } // while

        // get the right partition above

        const int partX_ = l;
        const int partY_ = numLeft - l;

        //* c1 is the max on the left part
        //* c2 is the min on the right part
        const int c1 = std::max(partX_ <= 0 ? INT_MIN : nums1[partX_ - 1],
                                partY_ <= 0 ? INT_MIN : nums2[partY_ - 1]);

        if ((n + m) % 2 == 1)
            return c1;

        const int c2 = std::min(partX_ >= m ? INT_MAX : nums1[partX_],
                                partY_ >= n ? INT_MAX : nums2[partY_]);

        return (c1 + c2) * 0.5;
    }
};
// @lc code=end
