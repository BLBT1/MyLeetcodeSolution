class Solution
{
public:
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c)
    {
        vector<int> res;
        // base on the value of a
        // if a is 0, already monotonic
        if (a == 0)
        {
            for (auto &i : nums)
            {
                int y = a * i * i + b * i + c;
                res.push_back(y);
            }
            if (b >= 0)
                return res;
            reverse(res.begin(), res.end());
            return res;
        }
        else
        {
            // a > 0  or a < 0
            // if a > 0, like a U, so greater abs(x) is greater f(x)
            // if a < 0, like a n, so smaller abs(x) is greater f(x)
            // use two pointer
            int l = 0, r = nums.size() - 1;
            // find the mid point -b/(2a), is a float
            double mid = double(-b) / (2.0 * double(a));
            while (l <= r)
            {
                if (abs(nums[l] - mid) >= abs(nums[r] - mid))
                {
                    int y = a * nums[l] * nums[l] + b * nums[l] + c;
                    res.push_back(y);
                    ++l;
                }
                else
                {
                    int y = a * nums[r] * nums[r] + b * nums[r] + c;
                    res.push_back(y);
                    --r;
                }
            }

            if (a > 0)
                reverse(res.begin(), res.end());
        }
        return res;
    }
};
