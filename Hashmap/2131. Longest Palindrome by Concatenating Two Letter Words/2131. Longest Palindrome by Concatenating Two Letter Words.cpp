class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int res = 0;
        unordered_map<string, int> cnt;
        unordered_map<string, int> cnt_same;
        for (auto s : words)
        {
            if (s[0] == s[1])
            {
                cnt_same[s]++;
            }
            else
            {
                cnt[s]++;
            }
        }

        int odd = 0;
        int cnt_even = 0;
        for (auto p : cnt_same)
        {
            if (p.second % 2 == 1)
            {
                if (odd == 0)
                    odd += 1;
                cnt_even += p.second - 1;
            }
            if (p.second % 2 == 0)
                cnt_even += p.second;
        }
        res += odd * 2;
        res += cnt_even * 2;

        for (auto s : words)
        {
            if (s[0] != s[1])
            {
                auto temp = s;
                reverse(temp.begin(), temp.end());
                if (cnt.find(temp) != cnt.end())
                {
                    res += min(cnt[s], cnt[temp]) * 4;
                    cnt.erase(temp);
                    cnt.erase(s);
                }
            }
        }
        return res;
    }
};