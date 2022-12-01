class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        unordered_set vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string first = s.substr(0, s.size() / 2);
        string second = s.substr(s.size() / 2);
        int cnt1 = 0, cnt2 = 0;
        for (auto c : first)
        {
            if (vow.find(c) != vow.end())
                cnt1++;
        }
        for (auto c : second)
        {
            if (vow.find(c) != vow.end())
                cnt2++;
        }
        return cnt1 == cnt2;
    }
};