class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int l = 1;
        int r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (countSmallerOrEqual(nums, mid) > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int countSmallerOrEqual(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (auto i : nums)
            if (i <= k)
                cnt++;
        return cnt;
    }
};

// binary search idea: 如果出现在k前面，那小于等于k的数字个数一定 > k
// O(NlogN)
