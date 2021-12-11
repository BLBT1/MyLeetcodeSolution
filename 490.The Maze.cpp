class Solution
{
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        using pos = pair<int, int>; //{y,x}

        const int m = maze.size();
        const int n = maze[0].size();

        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pos> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // all four diretion to move {y,x}

        // bfs
        queue<pos> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        while (!q.empty())
        {
            auto [curr_y, curr_x] = q.front();
            q.pop();
            if (curr_x == destination[1] &&
                curr_y == destination[0])
                return true;

            // store all four driection
            for (auto &dir : direction)
            {
                int x = curr_x + dir.second;
                int y = curr_y + dir.first;
                while (x >= 0 && y >= 0 &&
                       x < n && y < m &&
                       maze[y][x] == 0)
                {
                    x += dir.second;
                    y += dir.first;
                } //while

                x -= dir.second;
                y -= dir.first;

                if (!visited[y][x])
                {
                    q.push({y, x});
                    visited[y][x] = true;
                } //if
            }     //for
        }         //while

        return false;
    }
};