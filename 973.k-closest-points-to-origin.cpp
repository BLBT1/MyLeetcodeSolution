/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // * find kth smallest element from an unsorted list
        // * divide and conquer: QuickSelect()
        // make the list
        vector<pair<long long, int>> nums; // {long long = dist Square, idx}
        for (int i = 0; i < points.size(); ++i)
        {
            long long dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            nums.push_back({dist, i});
        }

        // find kth smallest dist from origin
        long long kthSmallest = QuickSelect(0, nums.size() - 1, k, nums);
        // cout << kthSmallest << endl;

        vector<vector<int>> res;
        for (auto &pos : nums)
        {
            if (pos.first <= kthSmallest)
                res.push_back(points[pos.second]);
        }

        return res;
    }

    long long QuickSelect(int begin, int end, int k, vector<pair<long long, int>> &nums)
    {
        // 1. randomly select a pivot p
        // 2. rank(p) : split nums into 2 part(smaller, greater)
        // 3. recursively do the QuickSelect on one half
        long long pivot = nums[(begin + end) / 2].first;

        // rank (3ptr method)
        int i = begin; // it the first element after Smaller set
        int t = begin; // the element we now comp to pivot
        int j = end;   // first element before Greater set

        while (t <= j)
        {
            if (nums[t].first < pivot)
            {
                swap(nums[t], nums[i]);
                i++;
                t++;
            }
            else if (nums[t].first > pivot)
            {
                swap(nums[t], nums[j]);
                j--;
            }
            else
            {
                t++;
            }
        } //while

        int numSmaller = i - begin;

        if (k <= numSmaller)
        {
            return QuickSelect(begin, i - 1, k, nums);
        }
        else if (k <= j - begin + 1)
        {
            return pivot;
        }
        else
        {
            return QuickSelect(j + 1, end, k - (j - begin + 1), nums);
        }
    }
};
// @lc code=end

// S S S S p L L L L L

// S   S S S p p p L L L L L L
// beg       i              end
//               t
//               j
