class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int low = 0;
        int hi = citations.size() - 1;
        while (low < hi)
        {
            int mid = (hi - low) / 2 + low;
            if (citations[mid] >= n - mid)
            {
                hi = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return min(n - low, citations[low]);
    }
};

// [100]
// 1
// 3
// [0,1,3,5,6]