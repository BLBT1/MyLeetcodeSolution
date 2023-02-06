class Solution
{
public:
    int maximizeSweetness(vector<int> &sweetness, int k)
    {
        // find max min subarray sum
        int low = *min_element(sweetness.begin(), sweetness.end());
        int hi = accumulate(sweetness.begin(), sweetness.end(), 0);
        while (low < hi)
        {
            int mid = low + (hi - low + 1) / 2;
            if (canGet(sweetness, k, mid))
                low = mid;
            else
                hi = mid - 1;
        }
        return low;
    }

    int canGet(vector<int> &sweetness, int k, int m)
    {
        // greedy to make each subarray sum to have at least m
        int n = sweetness.size();
        int i = 0;
        int cnt = 0;
        int sum = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && sum < m)
            {
                sum += sweetness[j];
                j += 1;
            }
            if (sum >= m)
            {
                cnt += 1;
                sum = 0;
            }
            i = j;
        }
        return cnt >= k + 1;
    }
};
