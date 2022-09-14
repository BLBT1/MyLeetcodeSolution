class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int rightMax = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > rightMax)
                return false;
            else
                rightMax = max(rightMax, i + nums[i]);
        }
        return rightMax >= nums.size() - 1;
    }
};
