class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        // max subarray min-product => max histgram
        stack<int> s;
        long res = 0L;
        const long Mod = 1000000007;

        vector<long> presum(nums.size() + 1);
        presum[0] = 0;
        for (long i = 0; i < nums.size(); ++i)
        {
            presum[i + 1] = presum[i] + nums[i];
        }

        for (long i = 0; i < nums.size(); ++i)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                long r = i;
                long h = nums[s.top()];
                s.pop();
                long l = s.empty() ? -1L : s.top();
                res = max(res, (static_cast<long>(presum[r] - presum[l + 1]) * h));
            }
            s.push(i);
        }

        long r = nums.size();
        while (!s.empty())
        {
            long h = nums[s.top()];
            s.pop();
            long l = s.empty() ? -1L : s.top();
            res = max(res, (static_cast<long>(presum[r] - presum[l + 1]) * h));
        }

        return res % Mod;
    }
};
