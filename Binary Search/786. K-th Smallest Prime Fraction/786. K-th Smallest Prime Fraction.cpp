class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &nums,
                                         int k)
    {
        // binary search on fraction
        double l = 0, r = 1;
        double mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            int cnt = cntSamllerEqual(nums, mid);
            if (cnt > k)
                r = mid;
            else if (cnt < k)
                l = mid;
            else
                break;
        }
        cout << mid << endl;
        // find the largest fraction that is smaller or equal to mid
        double res = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto pos = lower_bound(nums.begin(), nums.end(), nums[i] * 1.0 / mid);
            if (pos != nums.end() && nums[i] * 1.0 / (*pos) >= res)
            {
                res = nums[i] * 1.0 / (*pos);
                int j = pos - nums.begin();
                ans = {nums[i], nums[j]};
            }
        }
        return ans;
    }

    int cntSamllerEqual(vector<int> &nums, double mid)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto pos = lower_bound(nums.begin(), nums.end(), nums[i] * 1.0 / mid);
            cnt += nums.end() - pos;
        }
        return cnt;
    }
};
