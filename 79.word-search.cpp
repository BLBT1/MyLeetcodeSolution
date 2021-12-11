/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
    string word = "";
    string curr = "";
    int m = 0;
    int n = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        this->m = board.size();
        this->n = board[0].size();
        this->word = word;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                curr.push_back(board[i][j]);
                visited[i][j] = true;
                if (dfs(i, j, board, visited))
                    return true;
                curr.pop_back();
                visited[i][j] = false;
            }
        }
        return false;
    }

    // dfs start from (i,j)
    bool dfs(int i, int j,
             vector<vector<char>> &board,
             vector<vector<bool>> &visited)
    {
        if (curr.size() > word.size())
            return false;
        else if (curr.size() == word.size())
            if (curr == word)
            {
                return true;
            }
            else
                return false;
        else if (word.substr(0, curr.size()) != curr)
            return false;

        bool res = false;
        for (auto &dir : dirs)
        {
            int i_ = dir.first + i;
            int j_ = dir.second + j;
            if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || visited[i_][j_])
                continue;
            curr.push_back(board[i_][j_]);
            visited[i_][j_] = true;
            res = dfs(i_, j_, board, visited);
            visited[i_][j_] = false;
            curr.pop_back();
            if (res)
                return res;
        }

        return false;
    }
};
// @lc code=end

// return ture if a word is in the grid
// false otherwise
// dfs