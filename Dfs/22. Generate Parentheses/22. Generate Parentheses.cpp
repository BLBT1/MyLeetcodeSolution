class Solution
{
    vector<string> res;
    int n;

public:
    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        dfs("", 0, 0);
        return res;
    }

    void dfs(string curr, int left, int right)
    {
        if (left == n && right == n)
        {
            res.push_back(curr);
            return;
        }
        if (left < n)
            dfs(curr + "(", left + 1, right);

        if (right < left)
            dfs(curr + ")", left, right + 1);
    }
};