class Solution
{
    vector<vector<int>> res;
    vector<int> list;
    int sum = 0;
    int n;
    int tar;

public:
    vector<vector<int>> combinationSum2(vector<int> &cand, int tar)
    {
        sort(cand.begin(), cand.end());
        n = cand.size();
        this->tar = tar;
        dfs(cand, 0);
        return res;
    }

    void dfs(vector<int> &cand, int curr)
    {
        if (sum > tar)
        {
            return;
        }
        else if (sum == tar)
        {
            res.push_back(list);
            return;
        }
        for (int i = curr; i < n; ++i)
        {
            // only the first time meet can be added into list
            if (i != curr && i > 0 && cand[i] == cand[i - 1])
                continue;
            sum += cand[i];
            list.push_back(cand[i]);
            dfs(cand, i + 1);
            sum -= cand[i];
            list.pop_back();
        }
    }
};