class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int low = 0;
        int hi = *max_element(arr.begin(), arr.end());
        // 留下两个， 哪个近取哪个
        while (low + 1 < hi)
        {
            int mid = low + (hi - low) / 2;
            if (mutate(arr, mid) > target)
                hi = mid;
            else if (mutate(arr, mid) < target)
                low = mid;
            else
                return mid;
        }
        int distLow = abs(mutate(arr, low) - target);
        int distHi = abs(mutate(arr, hi) - target);
        if (distLow > distHi)
            return hi;
        return low;
    }

    int mutate(vector<int> &arr, int k)
    {
        int sum = 0;
        for (int i : arr)
        {
            if (i > k)
                sum += k;
            else
                sum += i;
        }
        return sum;
    }
};
