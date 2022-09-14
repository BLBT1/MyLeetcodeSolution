class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        const long mod = 1e9 + 7;
        // a*b => c, and a,b,c in arr
        unordered_map<int, long> mp; // {c, num} where with c as root, we have num ways to make binary trees
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            mp[arr[i]] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end())
                {
                    mp[arr[i]] += (mp[arr[j]] * mp[arr[i] / arr[j]]) % mod;
                }
            }
        }

        long res = 0;
        for (auto p : mp)
        {
            res += p.second;
        }
        return res % mod;
    }
};