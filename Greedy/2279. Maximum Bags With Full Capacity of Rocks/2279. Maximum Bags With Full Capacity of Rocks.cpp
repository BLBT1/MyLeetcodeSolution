class Solution
{
public:
    int maximumBags(vector<int> &caps,
                    vector<int> &rocks,
                    int ar)
    {
        int n = rocks.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i)
        {
            diff[i] = caps[i] - rocks[i];
        }

        sort(diff.begin(), diff.end());
        int sum = 0;
        int i = 0;
        for (; i < n; ++i)
        {
            sum += diff[i];
            if (sum > ar)
                break;
        }
        return i;
    }
};

// time:O(nlogn)
//  space O(n)