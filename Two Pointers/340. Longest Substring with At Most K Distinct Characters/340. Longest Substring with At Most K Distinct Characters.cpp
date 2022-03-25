class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        if (k == 0)
            return 0;
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char, int> Map;
        for (; r < s.size(); ++r)
        {
            if (Map.find(s[r]) != Map.end() || Map.size() < k)
            {
                Map[s[r]] = r;
            }
            else
            {
                // add this char would lead to more than k unique char
                // so we need to find the lestMost char
                char leftMost;
                int pos = s.size();
                for (auto &p : Map)
                {
                    if (p.second < pos)
                    {
                        pos = p.second;
                        leftMost = p.first;
                    }
                }
                // remove the leftMost and add in the newchar
                l = pos + 1;
                Map.erase(leftMost);
                Map[s[r]] = r;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};