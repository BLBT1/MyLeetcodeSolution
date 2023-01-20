class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        long lower = -1e9;
        long upper = 1e9;
        int mid;
        while (lower < upper)
        {
            mid = lower + (upper - lower) / 2;
            int cnt = cntSmallerOrEqual(mat, mid);
            if (cnt < k)
                lower = mid + 1;
            else
                upper = mid;
        }
        return lower;
    }

    int cntSmallerOrEqual(vector<vector<int>> &mat, int mid)
    {
        int cnt = 0;
        int m = mat.size();
        int n = mat[0].size();
        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n)
        {
            if (mat[i][j] <= mid)
            {
                cnt += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return cnt;
    }
};
