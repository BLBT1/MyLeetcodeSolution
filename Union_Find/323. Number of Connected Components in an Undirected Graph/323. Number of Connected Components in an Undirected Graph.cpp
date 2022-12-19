class Solution
{
    unordered_map<int, int> father;

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < n; ++i)
            father[i] = i;

        for (auto &e : edges)
        {
            if (findFather(e[0]) != findFather(e[1]))
                myUnion(e[0], e[1]);
        }

        unordered_set<int> comps;
        for (int i = 0; i < n; ++i)
        {
            int anc = findFather(i);
            comps.insert(anc);
        }

        return comps.size();
    }

    int findFather(int x)
    {
        if (x == father[x])
            return x;
        father[x] = findFather(father[x]);
        return father[x];
    }

    void myUnion(int i, int j)
    {
        i = findFather(i);
        j = findFather(j);
        if (i >= j)
            father[i] = father[j];
        else
            father[j] = father[i];
    }
};