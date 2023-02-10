class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int low = nums1.front() + nums2.front();
        int hi = nums1.back() + nums2.back();
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (cntSmallerEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                hi = mid;
        }
        int m = low;
        cout << m << endl;
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= m; ++j)
            {
                if (nums1[i] + nums2[j] < m)
                    res.push_back({nums1[i], nums2[j]});
            }

        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= m && res.size() < k; ++j)
            {
                if (nums1[i] + nums2[j] == m)
                    res.push_back({nums1[i], nums2[j]});
            }
        return res;
    }

    long cntSmallerEqual(vector<int> &nums1, vector<int> &nums2, int val)
    {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = n - 1;
        long cnt = 0;
        // think nums1 as row and nums2 as col; in lc378
        while (i < m && j >= 0)
        {
            while (i < m && nums1[i] + nums2[j] <= val)
            {
                cnt += j + 1;
                ++i;
            }
            --j;
        }
        return cnt;
    }
};

// 10
//        i
//    1 7 11
// 2  j
// 4
// 6
