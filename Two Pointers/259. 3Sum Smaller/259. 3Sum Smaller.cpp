class Solution
{
public:
    int threeSumSmaller(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target)
                {
                    res += r - l;
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return res;
    }
};