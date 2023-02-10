class Solution
{
public:
    int kthSmallestSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            presum[i + 1] = presum[i] + nums[i];
        cout << cntSmallerEqual(presum, 7) << endl;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (cntSmallerEqual(presum, mid) < k)
                low = mid + 1;
            else
                hi = mid;
        }
        return low;
    }

    int cntSmallerEqual(vector<int> &presum, int t)
    {
        int ret = 0;
        int j = 0;
        for (int i = 0; i < presum.size(); i++)
        {
            while (j < presum.size() && presum[j] - presum[i] <= t)
                j++;
            ret += j - (i + 1);
        }
        return ret;
    }
};

// 6
// [2,1,3]

// cnt = 6
// [0, 2, 3, 6]
//  i
// //  j

// [0, 3, 6, 11, 16]
//  i
//  j
