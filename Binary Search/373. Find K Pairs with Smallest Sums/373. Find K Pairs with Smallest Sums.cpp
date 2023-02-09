class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1,
                                       vector<int> &nums2,
                                       int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int low = nums1.front() + nums2.front();
        int hi = nums1.back() + nums2.back();
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (cntSmallerEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else // cnt smaller eq >= k
                hi = mid;
        }
        // know low is the smallest val st. at least k element smaller or eq to it
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n && nums1[i] + nums2[j] < low; ++j)
            {
                if (nums1[i] + nums2[j] < low)
                    res.push_back({nums1[i], nums2[j]});
            }
        }

        // add some equal pairs if smaller pairs are not enough
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n && nums1[i] + nums2[j] <= low && res.size() < k; j++)
            {
                if (nums1[i] + nums2[j] == low)
                    res.push_back({nums1[i], nums2[j]});
            }
        }

        return res;
    }

    // O(N) as i, j both move in one direction
    long cntSmallerEqual(vector<int> &nums1, vector<int> &nums2, int val)
    {
        long cnt = 0;
        int m = nums1.size();
        int n = nums2.size();
        int j = n - 1;
        // think like 378, but nums1 as a row, nums2 as a col
        for (int i = 0; i < m; ++i)
        {
            while (j >= 0 && nums1[i] + nums2[j] > val)
                --j;
            cnt += j + 1;
        }
        return cnt;
    }
};

//              j
//      [1, 7, 11]
//  2 i
//  4
//  6

// if nums1[i]+nums[j], then for all nums1[i_]+nums2[j] must also > k
