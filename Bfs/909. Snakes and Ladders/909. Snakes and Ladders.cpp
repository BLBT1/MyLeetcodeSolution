class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        // min move to get a point => bfs
        int n = board.size();
        int last = n * n;
        queue<int> q;
        vector<int> visited(n * n + 1, 0);
        q.push(1);
        visited[1] = 1;
        int step = 0;
        // row = n-1 - (i-1/n);
        // col = i%n - 1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                int curr = q.front();
                q.pop();
                if (curr == last)
                    return step;
                for (int next = curr + 1; next <= min(curr + 6, last); ++next)
                {
                    // get coord
                    int row = n - 1 - (next - 1) / n;
                    int col = row % 2 != n % 2 ? (next - 1) % n : n - 1 - (next - 1) % n;
                    cout << next << " " << row << " " << col << endl;
                    int dest = next;
                    if (board[row][col] != -1)
                        dest = board[row][col];
                    if (visited[dest])
                        continue;
                    visited[dest] = 1;
                    q.push(dest);
                }
            }
            step += 1;
        }
        return -1;
    }
};

// [[-1,-1,-1],
//  [-1,9,8],
//  [-1,8,9]]