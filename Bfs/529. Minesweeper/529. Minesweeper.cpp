class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int m = board.size();
        int n = board[0].size();
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[click[0]][click[1]] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int cnt = 0;
            vector<pair<int, int>> next_pts;
            if (board[curr.first][curr.second] == 'M')
            {
                board[curr.first][curr.second] = 'X';
                return board;
            }
            else
            {
                for (auto d : dir)
                {
                    int x = curr.first + d.first;
                    int y = curr.second + d.second;
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if (board[x][y] == 'M')
                        {
                            cnt++;
                        }
                        else
                        {
                            next_pts.push_back({x, y});
                        }
                    }
                }
                if (cnt != 0)
                {
                    board[curr.first][curr.second] = cnt + '0';
                }
                else
                {
                    board[curr.first][curr.second] = 'B';
                    for (auto &p : next_pts)
                    {
                        if (visited[p.first][p.second] == false)
                        {
                            visited[p.first][p.second] = true;
                            q.push(p);
                        }
                    }
                }
            }
        }
        return board;
    }
};