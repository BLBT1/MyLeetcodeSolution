class Solution
{
public:
    int countSegments(string s)
    {
        int cnt = 0;
        int i = 0;
        int j = 0;

        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        if (s.empty())
            return 0;

        while (s[i] == ' ')
            i++;
        if (i == s.size())
            return 0;

        while (i < s.size())
        {
            j = s.find(" ", i);
            if (j == -1)
                break;
            if (j > i)
                cnt++;
            i = j + 1;
        }

        ++cnt;

        return cnt;
    }
};