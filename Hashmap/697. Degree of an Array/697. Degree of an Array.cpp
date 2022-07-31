class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int maxFreq = 0;
        int maxElt = -1;
        int len = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (auto p : mp)
        {
            if (p.second.size() > maxFreq)
            {
                maxFreq = p.second.size();
                maxElt = p.first;
                len = p.second.back() - p.second.front() + 1;
            }
            else if (p.second.size() == maxFreq)
            {
                len = min(len, p.second.back() - p.second.front() + 1);
            }
        }
        return len;
    }
};