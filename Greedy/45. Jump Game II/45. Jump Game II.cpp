class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int beg = 0;
        int end = nums[0];
        if (nums.size() == 1)
            return 0;
        int step = 1;
        while (beg <= end)
        {
            int last_end = end;
            for (int i = beg; i <= last_end; ++i)
            {
                end = max(end, i + nums[i]);
                if (last_end >= nums.size() - 1)
                    return step;
            }
            beg = last_end + 1;
            step += 1;
        }
        return -1;
    }
};

// nums = [[2,3,1],1,4]
// b e