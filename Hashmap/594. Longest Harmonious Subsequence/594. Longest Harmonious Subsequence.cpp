class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        int res = 0;
        for (auto p : mp)
        {
            if (mp.find(p.first - 1) != mp.end())
                res = max(res, p.second + mp.find(p.first - 1)->second);
        }
        return res;
    }
};

// time: O(N)