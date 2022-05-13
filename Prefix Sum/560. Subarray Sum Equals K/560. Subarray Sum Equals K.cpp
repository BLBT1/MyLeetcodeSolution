class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // use idea of prefix sum
        // {prefix sum, cnt}
        int sum = 0;
        int res = 0;
        unordered_map<int, int> Map;
        // use prefix sum with N+1 size
        Map[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            int diff = sum - k;
            if (Map.find(diff) != Map.end())
            {
                res += Map[diff];
            }
            Map[sum]++;
        }
        return res;
    }
};