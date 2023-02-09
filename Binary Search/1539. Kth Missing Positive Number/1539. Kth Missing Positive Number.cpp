class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 1;
        int r = arr.back() + k;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (cntSmallerEq(arr, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int cntSmallerEq(vector<int> &arr, int val)
    {
        return val - (upper_bound(arr.begin(), arr.end(), val) - arr.begin());
    }
};

// 8 => missing = 8-5=> 4
// [2,3,4,7,11]

// l 2
// r 3
// [2]
