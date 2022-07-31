class Solution
{
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if (a.first != b.first)
                return a < b;
            else
                return a.second > b.second;
        }
    };

public:
    string addBoldTag(string s, vector<string> &words)
    {
        if (words.empty())
            return s;
        // step1: find intervals
        vector<pair<int, int>> ivl;
        for (auto &w : words)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                int j = s.find(w, i);
                if (j == -1)
                    break;
                ivl.push_back({j, j + w.size() - 1});
                i = j;
            }
        }
        // step2: merge interval (lc 56)
        if (ivl.empty())
            return s;
        vector<pair<int, int>> merged;
        vector<pair<int, int>> temp;
        for (auto &p : ivl)
        {
            temp.push_back({p.first, 1});
            temp.push_back({p.second, -1});
        }
        sort(temp.begin(), temp.end(), cmp());
        int cnt = 0;
        int beg, end;
        for (auto &p : temp)
        {
            cnt += p.second;
            if (cnt == 1 && p.second == 1)
                beg = p.first;
            if (cnt == 0 && p.second == -1)
            {
                end = p.first;
                merged.push_back({beg, end});
            }
        }
        vector<pair<int, int>> connected;
        connected.push_back(merged.front());
        if (merged.size() > 1)
        {
            for (int i = 1; i < merged.size(); ++i)
            {
                if (merged[i].first == connected.back().second + 1)
                    connected.back().second = merged[i].second;
                else
                    connected.push_back(merged[i]);
            }
        }

        // step3: generate res
        string res = "";
        int i = 0, j = 0;
        for (; i < s.size(); ++i)
        {
            bool flag1 = false;
            bool flag2 = false;
            if (j < connected.size() && i == connected[j].first)
            {
                res += "<b>";
                res.push_back(s[i]);
                flag1 = true;
            }
            if (j < connected.size() && i == connected[j].second)
            {
                if (!flag1)
                    res.push_back(s[i]);
                res += "</b>";
                j++;
                flag2 = true;
            }
            if (!flag1 && !flag2)
                res.push_back(s[i]);
        }
        return res;
    }
};

//  s = "aaabbcc", words = ["aaa","aab","bc"]

//      0 1 2 3 4 5 6
//      a a a b b c c
//      b   e
//        b   e
//               b e