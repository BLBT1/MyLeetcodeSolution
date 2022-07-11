class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &dest)
    {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        maze[start[0]][start[1]] = -1; // empty => 0, wall => 1 , visited => -1
        q.push({start[0], start[1]});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == dest[0] && y == dest[1])
                return true;

            for (auto d : dir)
            {
                int x_ = x + d.first;
                int y_ = y + d.second;

                // if not the wall or out of board, keep going
                while (x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && maze[x_][y_] != 1)
                {
                    x_ = x_ + d.first;
                    y_ = y_ + d.second;
                }

                // only record the place the ball stop
                x_ = x_ - d.first;
                y_ = y_ - d.second;
                if (maze[x_][y_] == 0)
                {
                    maze[x_][y_] = -1;
                    q.push({x_, y_});
                }
            }
        }
        return false;
    }
};
