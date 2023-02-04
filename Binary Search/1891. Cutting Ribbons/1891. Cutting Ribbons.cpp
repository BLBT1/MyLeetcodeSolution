class Solution
{
public:
    int maxLength(vector<int> &ribbons, int k)
    {
        int l = 0;
        int r = *max_element(ribbons.begin(), ribbons.end());
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (canGet(ribbons, k, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    bool canGet(vector<int> &ribbons, int k, int len)
    {
        int cnt = 0;
        for (int i = 0; i < ribbons.size(); ++i)
        {
            cnt += ribbons[i] / len;
        }
        return cnt >= k;
    }
};