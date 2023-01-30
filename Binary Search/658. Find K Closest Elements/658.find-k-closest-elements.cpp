class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr,
                                    int k,
                                    int x)
    {
        // O(logn) + O(klogk)
        int l = 0;
        int r = arr.size() - 1;
        int mid;
        while (l + 1 < r)
        {
            mid = l + (r - l) / 2;
            if (arr[mid] < x)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        vector<int> res;
        while (res.size() < k)
        {
            if (l < 0)
            {
                res.push_back(arr[r]);
                r += 1;
            }
            else if (r >= arr.size())
            {
                res.push_back(arr[l]);
                l -= 1;
            }
            else if (abs(arr[l] - x) > abs(arr[r] - x))
            {
                res.push_back(arr[r]);
                r += 1;
            }
            else
            {
                res.push_back(arr[l]);
                l -= 1;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};