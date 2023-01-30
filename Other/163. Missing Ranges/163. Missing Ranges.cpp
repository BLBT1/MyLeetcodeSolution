class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums,
                                     int lower, int upper)
    {
        vector<string> res;
        if (nums.size() == 0)
        {
            if (upper - lower + 1 > 1)
                res.push_back(to_string(lower) + "->" + to_string(upper));
            else
                res.push_back(to_string(lower));
            return res;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                if (nums[i] > lower)
                {
                    if (nums[i] - lower > 1)
                        res.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
                    else
                        res.push_back(to_string(lower));
                }
            }
            else
            {
                if (nums[i] - nums[i - 1] > 1 && nums[i - 1] >= lower)
                {
                    int a = nums[i - 1] + 1;
                    int b = min(upper, nums[i] - 1);
                    // missing range [a:b]
                    if (b - a + 1 > 1)
                        res.push_back(to_string(a) + "->" + to_string(b));
                    else
                        res.push_back(to_string(a));
                }
            }
            if (nums[i] > upper)
                break;
        }
        if (nums.back() < upper)
        {
            if (upper - nums.back() == 1)
                res.push_back(to_string(upper));
            else
                res.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }
        return res;
    }
};

// lower = 0
// // upper = 99
// [0,1,3,50,75]
//      i
