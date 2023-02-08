class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int start = 0;
        int end = 0;
        int step = 0;
        if (nums.size() == 1)
            return 0;
        // to two pointer to simulate a queue in bfs
        while (start <= end)
        {
            step++;
            int maxReach = end;
            for (int next = start; next <= end; ++next)
            {
                maxReach = max(maxReach, next + nums[next]);
                if (maxReach >= nums.size() - 1)
                    return step;
            }
            start = end + 1;
            end = maxReach;
        }
        return -1;
    }
};

// mr = 4;
// [2,3,1,1,4]
//    s
//      e