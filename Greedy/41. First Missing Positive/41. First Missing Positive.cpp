class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        nums.insert(nums.begin(), 0);
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i)
                return i;
        }

        return nums.size();
    }
};