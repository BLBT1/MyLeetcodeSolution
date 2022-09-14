class Solution
{
public:
    int shortestWay(string src, string tar)
    {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < src.size(); ++i)
            mp[src[i]].push_back(i);

        for (auto c : tar)
        {
            if (mp.find(c) == mp.end())
                return -1;
        }

        int itr = 1;
        int pos = -1; // find after -1
        int k = 0;
        while (k < tar.size())
        {
            char c = tar[k];
            bool flag = false;
            for (auto i : mp[c])
            {

                if (i > pos)
                {
                    pos = i;
                    flag = true;
                    ++k;
                    break;
                }
            }
            if (flag == false)
            {
                itr++;
                pos = -1;
            }
        }

        return itr;
    }
};