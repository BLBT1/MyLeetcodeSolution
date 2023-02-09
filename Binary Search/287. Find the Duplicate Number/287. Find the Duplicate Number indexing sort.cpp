class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            while (nums[i] - 1 != i && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
            ++i;
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] - 1 != i)
                return nums[i];
        }
        return -1;
    }
};

// [1, 2, 2, 3, 4]
