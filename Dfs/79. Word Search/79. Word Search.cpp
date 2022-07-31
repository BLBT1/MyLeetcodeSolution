class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n, m;
    string word;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        this->word = word;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if (dfs(board, visited, i, j, 1) == true)
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int curr)
    {
        if (curr == word.size())
        {
            return true;
        }
        for (auto &d : dir)
        {
            int i = x + d.first;
            int j = y + d.second;
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
                continue;
            if (word[curr] != board[i][j])
                continue;
            visited[i][j] = true;
            if (dfs(board, visited, i, j, curr + 1))
                return true;
            visited[i][j] = false;
        }
        return false;
    }
};
