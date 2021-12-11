/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        /*
        * O(n+m) time
        * O(n+m) space 
        * */
        vector<int> res;
        myUnion(nums1,
                nums2,
                res,
                0, m,
                0, n);
        nums1 = res;
    }

    void myUnion(const vector<int> &nums1,
                 const vector<int> &nums2,
                 vector<int> &res,
                 int begin1, int end1,
                 int begin2, int end2)
    {
        res.reserve((end2 - begin2) + (end1 - begin1));
        while (begin1 != end1 && begin2 != end2)
        {
            if (nums1[begin1] < nums2[begin2])
            {
                res.push_back(nums1[begin1++]);
            }
            else
            {
                res.push_back(nums2[begin2++]);
            }
        }
        while (begin1 != end1)
        {
            res.push_back(nums1[begin1++]);
        }
        while (begin2 != end2)
        {
            res.push_back(nums2[begin2++]);
        }
    }
};
// @lc code=end
