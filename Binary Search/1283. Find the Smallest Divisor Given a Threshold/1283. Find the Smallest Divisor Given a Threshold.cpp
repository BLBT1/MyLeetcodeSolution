class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int hi = *max_element(nums.begin(), nums.end()) + 1;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (isValid(nums, threshold, mid))
                hi = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    bool isValid(vector<int> &nums, int threshold, int mid)
    {
        int sum = 0;
        for (auto i : nums)
        {
            if (i % mid != 0)
                sum += i / mid + 1;
            else
                sum += i / mid;
        }
        return sum <= threshold;
    }
};

// find smallest divisor such that sum of all division is <= to threshold