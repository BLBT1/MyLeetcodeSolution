class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        // O(Nlog(S)), S is sum of array, N is size of array

        int lower = *max_element(nums.begin(), nums.end());
        int upper = accumulate(nums.begin(), nums.end(), 0);
        while (lower < upper)
        {
            int mid = lower + (upper - lower) / 2;
            if (check(nums, k, mid))
                upper = mid;
            else
                lower = mid + 1;
        }
        return lower;
    }

    // greedy check if we can split nums into k group that each group has sum < mid
    // O(N)
    bool check(vector<int> &nums, int k, int mid)
    {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            cnt += 1;
            int j = i;
            while (j < nums.size() && sum + nums[j] <= mid)
            {
                sum += nums[j];
                ++j;
            }
            i = j - 1;
            sum = 0;
        }
        return cnt <= k;
    }
};

// lower = 10, upper = 21
// mid = 15
// sum
// cnt = 2 <= k
// [7,2,5,10,8],
