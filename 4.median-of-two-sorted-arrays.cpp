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
        const int m = nums1.size();
        const int n = nums2.size();

        if ((m + n) % 2 == 0)
            return ((findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1))) / 2;
        else
            return findKth(nums1, nums2, (m + n) / 2 + 1);
    }

    struct comp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        }
    };

    double findKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;

        int count = 0;
        int i = 0;
        int j = 0;

        if (nums1.size() != 0)
        {
            q.push({nums1[0], 1});
            i++;
        }
        if (nums2.size() != 0)
        {
            q.push({nums2[0], 2});
            j++;
        }

        int res;
        while (count < k)
        {
            int label = q.top().second;
            res = q.top().first;
            q.pop();
            count++;
            if (label == 1 && i < nums1.size())
            {
                q.push({nums1[i], 1});
                i++;
            }
            else if (label == 2 && j < nums2.size())
            {
                q.push({nums2[j], 2});
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
