class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // to deal with the follow-up
        // what if we have seq of s1...sk for t
        // we need to use a map to all the occurance of vals
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < t.size(); i++)
            mp[t[i]].push_back(i);

        int pos = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            bool flag = false;
            char ch = s[i];
            for (auto j : mp[ch])
            {
                if (j > pos)
                {
                    flag = true;
                    pos = j;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};