class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equ,
                                vector<double> &val,
                                vector<vector<string>> &queries)
    {
        // a->(2.0)->b->(3.0)->c
        // a->c => 6.0
        // this is acutally a graph problem
        unordered_map<string, vector<pair<string, double>>> mp;
        for (int i = 0; i < equ.size(); ++i)
        {
            mp[equ[i][0]].push_back({equ[i][1], val[i]});
            mp[equ[i][1]].push_back({equ[i][0], 1 / val[i]});
        }

        vector<double> res;
        for (auto q : queries)
        {
            if (mp.find(q[1]) == mp.end())
            {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(dfs(mp, visited, q[0], q[1]));
        }
        return res;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>> &mp,
               unordered_set<string> &visited,
               string curr, string target)
    {
        if (curr == target)
            return 1.0;
        visited.insert(curr);
        for (auto next : mp[curr])
        {
            string nextStr = next.first;
            double dist = next.second;
            if (visited.find(nextStr) != visited.end())
                continue;
            double reach = dfs(mp, visited, nextStr, target);
            if (reach == -1.0)
                continue;
            else
                return dist * reach;
        }
        visited.erase(curr);
        return -1.0;
    }
};
