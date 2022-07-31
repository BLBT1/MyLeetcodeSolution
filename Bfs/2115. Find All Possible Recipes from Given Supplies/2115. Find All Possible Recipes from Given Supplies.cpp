class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingred,
                                  vector<string> &supplies)
    {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, int> indeg;
        for (int i = 0; i < recipes.size(); ++i)
        {
            for (int j = 0; j < ingred[i].size(); ++j)
            {
                mp[ingred[i][j]].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }
        vector<string> res;
        queue<string> q;
        for (int i = 0; i < supplies.size(); ++i)
        {
            q.push(supplies[i]);
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (auto next : mp[curr])
            {
                indeg[next]--;
                if (indeg[next] == 0)
                {
                    res.push_back(next);
                    q.push(next);
                }
            }
        }

        return res;
    }
};