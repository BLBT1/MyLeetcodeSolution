class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int low = 0;
        int hi = 1e6;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (cntSmallerEqual(nums, mid) < k)
                low = mid + 1;
            else
                hi = mid;
        }
        return low;
    }

    int cntSmallerEqual(vector<int> &nums, int m)
    {
        int i = 0;
        int j = 0;
        int cnt = 0;
        // 固定左指针，看右指针最远能到哪里
        while (i < nums.size() - 1)
        {
            while (j < nums.size() && nums[j] - nums[i] <= m)
                ++j;
            cnt += j - 1 - i;
            ++i;
        }
        return cnt;
    }
};
