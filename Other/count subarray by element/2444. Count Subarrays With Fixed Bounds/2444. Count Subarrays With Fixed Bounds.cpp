class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long res = 0;
        int boundary = -1, preMin = -1, preMax = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                boundary = i;
                continue; // boundary cannot be in any subarray, so must not be consider as right bound
            }
            if (nums[i] == minK)
                preMin = i;
            if (nums[i] == maxK)
                preMax = i;
            res += max(0, min(preMin, preMax) - boundary);
        }
        return res;
    }
};
// 固定右边界， 再思考左边界， 哪些位置能作为subarray的起点
// 这样对于每个新的右边界找左边界， 不会重复考虑任何subarray

// [B X preMax X preMin X i]

// B is boundary that  B > preMax || B < preMin

// 那 (B, min(preMin, preMax)] 的位置都是可以作为新subarray的。

// res += min(preMin, preMax) - B
