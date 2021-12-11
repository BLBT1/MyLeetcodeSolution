class Solution
{
public:
    int numWays(int n, int k)
    {
        // two states:
        // same: nums[i-1] == nums[i]
        // diff : nums[i-1] != nums[i]
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        int same = k;
        int diff = k * (k - 1);
        for (int i = 2; i < n; ++i)
        {
            int old_same = same;
            int old_diff = diff;
            same = old_diff;
            diff = old_same * (k - 1) + old_diff * (k - 1);
        }

        return same + diff;
    }
};