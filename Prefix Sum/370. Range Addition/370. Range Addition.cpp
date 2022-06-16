class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        // lazy propagation
        vector<int> nums(length, 0);
        for (auto &up : updates)
        {
            int st = up[0];
            int end = up[1];
            int val = up[2];

            nums[st] += val;
            if (end + 1 < nums.size())
                nums[end + 1] -= val;
        }

        // prefix sum
        int sum = 0;
        for (auto &i : nums)
        {
            sum += i;
            i = sum;
        }

        return nums;
    }
};
