class Solution
{
public:
    unordered_map<int, int> groups; //{v, group}

    static bool mycomp(vector<int> &a, vector<int> &b)
    {
        if (a[2] != b[2])
            return a[2] < b[2];
        return true;
    }

    int minimumCost(int n, vector<vector<int>> &connections)
    {
        const int E = connections.size();
        int cost = 0;
        int numEdge = 0;
        // Kruskal(greedy + union-find)
        // 1. sort all the given edges by cost asc + init groups
        sort(connections.begin(), connections.end(), mycomp);

        for (int i = 1; i <= n; ++i)
            groups[i] = i;

        for (int i = 0; i < E; ++i)
        {
            int v1 = connections[i][0];
            int v2 = connections[i][1];
            int edgeCost = connections[i][2];

            // if not int a group(not connected)
            if (find(v1) != find(v2))
            {
                unionfiy(v1, v2);
                cost += edgeCost;
                numEdge++;
            }

            if (numEdge == n - 1)
                return cost;
        }

        for (int i = 1; i <= n; i++)
        {
            if (find(i) != find(i - 1))
                return -1;
        }

        return cost;
    }

    int find(int i)
    {
        if (groups[i] == i)
            return i;
        else

            // path compression
            groups[i] = find(groups[i]);
        return groups[i];
    }

    void unionfiy(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        groups[x] = y;
    }
};

// connections[i] = (xi, yi, cost_i);
// return the min cost of connecting all n cities
// if impossible to connect return -1
// MST
// Kruskal
