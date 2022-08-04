class Solution
{
    unordered_set<int> st;
    unordered_map<int, int> father;

public:
    int longestConsecutive(vector<int> &nums)
    {

        for (auto n : nums)
        {
            if (father.find(n) == father.end())
            {
                st.insert(n);
                father[n] = n;
            }

            if (father.find(n - 1) != father.end() && findFather(n - 1) != findFather(n))
                Union(n - 1, n);
            if (father.find(n + 1) != father.end() && findFather(n + 1) != findFather(n))
                Union(n + 1, n);
        }

        for (auto x : st)
            father[x] = findFather(x);

        unordered_map<int, int> cnt;
        for (auto p : father)
        {
            cnt[p.second]++;
        }
        int res = 0;
        for (auto p : cnt)
        {
            if (p.second > res)
                res = p.second;
        }
        return res;
    }

    int findFather(int x)
    {
        if (father[x] != x)
            father[x] = findFather(father[x]);
        return father[x];
    }

    void Union(int x, int y)
    {
        int xFather = findFather(x);
        int yFather = findFather(y);
        if (xFather > yFather)
            father[y] = xFather;
        else
            father[x] = yFather;
    }
};

// nu