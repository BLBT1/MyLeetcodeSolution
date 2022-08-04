class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // do dfs to all the smallest numbers in the sequence
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto x : nums)
        {
            if (st.find(x - 1) == st.end())
            {
                // then x is the begin of the chain
                // we need to find the whole chain
                int cnt = 1;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};