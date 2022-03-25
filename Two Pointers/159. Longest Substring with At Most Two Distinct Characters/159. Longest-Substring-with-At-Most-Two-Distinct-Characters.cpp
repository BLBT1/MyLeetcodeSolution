class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        unordered_map<char, int> Map; // {char, postion of last appear}
        int i = 0;
        int j = 0;
        int res = 0;
        for (; j < s.size(); ++j)
        {
            if (Map.find(s[j]) != Map.end())
            {
                // s[j] already in the map
                Map[s[j]] = j;
            }
            else if (Map.size() < 2)
            {
                Map[s[j]] = j;
            }
            else
            {
                char leftMost;
                int pos = s.size();
                for (auto &pair : Map)
                {
                    if (pair.second < pos)
                    {
                        pos = pair.second;
                        leftMost = pair.first;
                    }
                }
                Map.erase(leftMost);
                Map[s[j]] = j;
                i = max(i, pos + 1);
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};