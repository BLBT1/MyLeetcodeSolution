class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> maxSum(n, INT_MIN);
        vector<int> minSum(n, INT_MAX);
        maxSum[0] = minSum[0] = nums[0];
        int res = INT_MIN;
        int allNeg = true; // if all element is nagative
        if (nums[0] >= 0)
            allNeg = false;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] >= 0)
                allNeg = false;
            maxSum[i] = max(maxSum[i - 1] + nums[i], nums[i]);
            minSum[i] = min(minSum[i - 1] + nums[i], nums[i]);
            res = max(maxSum[i], res);
            res = max(totalSum - minSum[i], res);
            res = max(nums[i], res);
        }
        // corner case: if all num is negative, then the res should be max element in array, otherwise would return 0 which is wrong
        if (allNeg)
            return *max_element(nums.begin(), nums.end());
        else
            return res;
    }
};

// [3}, -1, {3] => {3, 3}
// max circular sum = total - min =
