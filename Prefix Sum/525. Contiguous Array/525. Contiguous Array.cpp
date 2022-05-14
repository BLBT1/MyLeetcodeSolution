class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = nums[i] == 0 ? -1 : 1;

        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (mp.find(sum) != mp.end())
            {
                res = max(i - mp[sum], res);
            }
            else
            {
                mp[sum] = i;
            }
        }

        return res;
    }
};

// [0,1,0]
