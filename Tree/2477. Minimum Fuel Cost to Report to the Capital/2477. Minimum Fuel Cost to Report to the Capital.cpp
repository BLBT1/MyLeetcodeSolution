class Solution
{
    int n;

public:
    long long minimumFuelCost(vector<vector<int>> &roads,
                              int seats)
    {
        unordered_map<int, vector<int>> tree;
        n = roads.size() + 1;
        vector<int> visited(n, 0);
        visited[0] = 1;
        for (auto e : roads)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<long long> res = dfs(tree, seats, 0, visited); //{num feul, nums cars, num Rep}
        return res[0];
    }

    vector<long long> dfs(unordered_map<int, vector<int>> &tree, int seats, int curr, vector<int> &visited)
    {
        long long numCars = 0;
        long long numFuel = 0;
        long long numRep = 0;
        for (int next : tree[curr])
        {
            if (visited[next] == 1)
                continue;
            visited[next] = 1;
            auto p = dfs(tree, seats, next, visited);
            numCars += p[1];
            numFuel += p[0];
            numRep += p[2];
        }

        numFuel += numCars;
        numRep += 1; // add the curr node
        if (numRep % seats > 0)
            numCars = numRep / seats + 1;
        else
            numCars = numRep / seats;
        return {numFuel, numCars, numRep};
    }
};