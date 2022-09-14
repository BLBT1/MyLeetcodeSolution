class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long missing = 1;
        int add = 0;
        int i = 0;
        while (missing <= n)
        {
            if (i < nums.size() && nums[i] <= missing)
            {
                missing += nums[i];
                ++i;
            }
            else
            {
                add += 1;
                missing += missing;
            }
        }

        return add;
    }
};

// find how far we can get prev miss  + nums[i]
// greedy: try ours best to use the num in nums to expand the range we can reach by our sum
// if nums[i] <= miss, miss = miss+nums[i]
// else added+1, miss+1

// ex:
// nums = [1, 2, 4, 13, 43], n = 100
// [0, 1) missing: 1, nums[i] <= missing
// [0, 2) missing: 2
// [0, 4) missing: 4
// [0, 8) missing: 8 nums[i] <= 8? do need to add a 8
// [0, 16) missing: 16 nums[i] < 16
// [0, 29) missing: 29, need to add 29
// [0, 58] missing 58
// [0, 101) missing 101 > n, we are all good

// missing < n
