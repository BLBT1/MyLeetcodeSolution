class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vow_list = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_map<int, int> vow_map;
        string vows;
        unordered_map<int, char> rest_map;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (vow_list.find(c) != vow_list.end())
            {
                vows.push_back(c);
                vow_map[i] = vows.size() - 1;
            }
            else
            {
                rest_map[i] = c;
            }
        }

        if (!vows.empty())
            reverse(vows.begin(), vows.end());

        string res = "";
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (vow_map.find(i) != vow_map.end())
            {
                res.push_back(vows[vow_map[i]]);
            }
            else
            {
                res.push_back(rest_map[i]);
            }
        }
        return res;
    }
};

// oe
// vow_map
// (1, 0)
// (5, 1)

// rest_map
// (0, h)
// (2, l)
// (3, l))
