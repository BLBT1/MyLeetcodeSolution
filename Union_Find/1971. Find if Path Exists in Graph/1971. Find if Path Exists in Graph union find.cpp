class Solution
{
    unordered_map<int, int> father;

public:
    bool validPath(int n, vector<vector<int>> &edges, int src, int dest)
    {
        for (int i = 0; i < n; ++i)
            father[i] = i;

        for (auto e : edges)
        {
            if (findFather(e[0]) != findFather(e[1]))
                myUnion(e[0], e[1]);
        }

        return findFather(src) == findFather(dest);
    }

    // O(nlogn)
    int findFather(int x)
    {
        if (father[x] == x)
            return father[x];

        father[x] = findFather(father[x]);
        return father[x];
    }

    // O(nlog(n))
    void myUnion(int i, int j)
    {
        i = findFather(i);
        j = findFather(j);
        if (i <= j)
            father[j] = i;
        else
            father[i] = j;
    }
};