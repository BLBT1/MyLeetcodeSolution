
class Solution
{
    using pos = vector<int>;

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &dest)
    {
        // You actually can revisited a location, as long as your current travaled distance is smaller than the previous visit.
        int m = maze.size();
        int n = maze[0].size();
        // bfs + bq:
        priority_queue<pos, vector<pos>, greater<>> pq;
        pq.push({0, start[0], start[1]});
        maze[start[0]][start[1]] = -1;
        while (!pq.empty())
        {
            int x = pq.top()[1];
            int y = pq.top()[2];
            int dist = pq.top()[0];
            pq.pop();

            // You actually can revisited a location, as long as your current travaled distance is smaller than the previous visit.
            maze[x][y] = -1;

            if (x == dest[0] && y == dest[1])
                return dist;

            for (auto d : dir)
            {
                int step = 0;
                int a = x + d.first;
                int b = y + d.second;
                while (a >= 0 && b >= 0 && a < m && b < n && maze[a][b] != 1)
                {
                    step++;
                    a = a + d.first;
                    b = b + d.second;
                }
                a = a - d.first;
                b = b - d.second;

                if (maze[a][b] == 0)
                {
                    // maze[a][b] = -1;
                    pq.push({dist + step, a, b});
                }
            }
        }
        return -1;
    }
};