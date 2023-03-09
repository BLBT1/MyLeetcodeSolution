class Solution
{
    vector<int> temp;

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        temp = vector<int>(n + 1);
        int res = merge_sort(nums, 0, nums.size() - 1);
        return res;
    }

    int merge_sort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return 0;
        int cnt = 0;

        int mid = l + (r - l) / 2;

        cnt += merge_sort(nums, l, mid);
        cnt += merge_sort(nums, mid + 1, r);

        for (int j = mid + 1; j <= r; ++j)
        {
            auto pos = upper_bound(nums.begin() + l, nums.begin() + mid + 1, (long long)nums[j] * 2);
            cnt += nums.begin() + mid + 1 - pos;
        }
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= r)
            temp[k++] = nums[j++];
        i = l;
        k = 0;
        while (i <= r)
            nums[i++] = temp[k++];
        return cnt;
    }
};