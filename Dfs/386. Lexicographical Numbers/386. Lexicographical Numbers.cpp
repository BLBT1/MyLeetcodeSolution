class Solution
{
    vector<int> res;

public:
    vector<int> lexicalOrder(int n)
    {
        dfs(0, n);
        return res;
    }

    void dfs(int curr, int n)
    {
        if (curr > n)
            return;
        if (curr != 0)
            res.push_back(curr);
        for (int i = 0; i <= 9; ++i)
        {
            int next = curr * 10 + i;
            if (next == 0)
                continue;
            if (next > n)
                break;
            dfs(next, n);
        }
    }
};