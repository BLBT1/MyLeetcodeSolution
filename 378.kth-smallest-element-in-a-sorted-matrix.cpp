/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    struct myCmp
    {
        bool operator()(const pair<int, int> &v1, const pair<int, int> &v2) const
        {
            return v1.first > v2.first;
        }
    };

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // thinking like bfs
        // store both val and pos
        const int n = matrix.size();

        // push in the first element
        auto visited = vector<vector<int>>(n, vector<int>(n, 0));
        visited[0][0] = 1;

        // because we know it is a n*n mat
        // so we can only use a single to rep (i,j)
        // pos = i*n +j
        // to retrieve i,j
        // i = pos/i
        // j= pos%n
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> q;
        q.push({matrix[0][0], 0});
        int count = 0;

        while (count < k - 1)
        {
            // pop the top
            int i = q.top().second / n;
            int j = q.top().second % n;
            q.pop();
            count++;

            if (i + 1 < n && j < n && visited[i + 1][j] == 0)
            {
                q.push({matrix[i + 1][j], (i + 1) * n + j});
                visited[i + 1][j] = 1;
            }
            if (i < n && j + 1 < n && visited[i][j + 1] == 0)
            {
                q.push({matrix[i][j + 1], (i)*n + j + 1});
                visited[i][j + 1] = 1;
            }
        }

        return q.top().first;
    }
};
// @lc code=end
