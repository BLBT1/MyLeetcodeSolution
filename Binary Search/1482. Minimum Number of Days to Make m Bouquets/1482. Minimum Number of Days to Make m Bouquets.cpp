class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int l = 1;
        int r = 1e9;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (canGet(bloomDay, m, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return canGet(bloomDay, m, k, l) ? l : -1;
    }

    // need to find m k size subarray <= day
    bool canGet(vector<int> &bloomDay, int m, int k, int day)
    {
        int n = bloomDay.size();
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i)
        {
            int j = i; // nums[i:j)
            while (j < n && bloomDay[j] <= day && j - i < k)
                ++j;
            if (j - i == k)
                cnt += 1;
            i = max(i, j - 1);
        }
        return cnt >= m;
    }
};

// [1,10,2,9,3,8,4,7,5,6]
//  i
//  j
// m 4
// k 2
