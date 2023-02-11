class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int low = 1;
        int hi = m * n;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (cntSmallerEqual(m, n, mid) < k)
                low = mid + 1;
            else
                hi = mid;
        }
        return low;
    }

    int cntSmallerEqual(int m, int n, int val)
    {
        int i = m - 1;
        int j = 0;
        int cnt = 0;
        while (i >= 0 && j < n)
        {
            if ((i + 1) * (j + 1) <= val)
            {
                cnt += i + 1;
                ++j;
            }
            else
            {
                --i;
            }
        }
        return cnt;
    }
};

// kth smallest elt in a sorted mat => lc378?