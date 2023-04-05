class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int l = nums[0], r = 1e9;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (!isValid(nums, mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }

    // given x, return if it is a possible min val of max integer in array
    bool isValid(vector<int> &nums, int x)
    {
        long long buffer = x - nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            long long diff = nums[i] - x;
            if (diff > buffer)
            {
                return false;
            }
            buffer -= diff;
        }
        return true;
    }
};

// [2, 7, 9, 19, 5, 19]

// 对于 indx 1 之后的数字， 都可以让他-1， 前面的数字+1
// 也就是后面的数字可以往前面挪动
// 假设最后答案是x，
// nums[1] can only move the exceed part to nums[0]
// nums[2] can move the excced part to nums[0: 1]
// nums[3] ....  nums[0:2]
// nums[i] .... nums[0:i-1], we define the remaining space in nums[0 : i-1] as buffer
// buffer is x*i - sum(num[0: i-1])...
// in this way, given a guess x, we can figure if it is ans in O(N) time, n is lenght of array
// Time: O(N*log(M)), M is the max val of nums[i]