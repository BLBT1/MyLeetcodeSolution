class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                cnt++;
                // first: nums[i-1] = nums[i]
                // ex: nums[i-2] < nums[i]
                // [3,4,2,3]
                if (i < 2 || (i >= 2 && nums[i - 2] <= nums[i]))
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
            if (cnt > 1)
                return false;
        }

        return true;
    }
};

// [4,2,3]

// [3,4,2,3]