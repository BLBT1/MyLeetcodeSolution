class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        multiset<int> ms;
        for (auto i : nums1)
            ms.insert(i);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            auto it = ms.upper_bound(nums2[i]);
            if (it != ms.end())
            {
                ans[i] = *it;
                ms.erase(it);
            }
        }
        auto it = ms.begin();
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = *it;
                it++;
            }
        }
        return ans;
    }
};