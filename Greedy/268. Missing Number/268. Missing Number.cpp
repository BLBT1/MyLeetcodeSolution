class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        nums.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            while (i != nums[i] && nums[i] != nums[nums[i]] && i < n && nums[i] < n)
                swap(nums[i], nums[nums[i]]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i)
                return i;
        }

        return n;
    }
};