/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */

// @lc code=start

using PII = pair<int, int>;
class Solution
{
    double n = 1e6;
    int MAX_ENCLOSE = 19900; // 200格子斜着围角
    vector<pair<int, int>> dirs = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    enum class Status
    {
        MEET,     // begin meet end
        ENCLOSED, // begin is enclosed
        NENCLOSED // begin is not enclosed
    };

public:
    bool isEscapePossible(vector<vector<int>> &blocked,
                          vector<int> &source,
                          vector<int> &target)
    {
        PII src = {source[0], source[1]};
        PII tar = {target[0], target[1]};

        set<pair<int, int>> blocks;

        for (auto &b : blocked)
            blocks.insert({b[0], b[1]});

        auto fromSrc = bfs(blocks, src, tar);

        if (fromSrc == Status::MEET)
            return true;
        else if (fromSrc == Status::ENCLOSED)
            return false;

        auto fromTar = bfs(blocks, tar, src);
        return fromTar != Status::ENCLOSED;
    }

    Status bfs(set<pair<int, int>> &blocks,
               PII &begin,
               PII &end)
    {
        queue<PII> q;
        set<PII> visited;
        q.push(begin);
        visited.insert(begin);

        while (!q.empty())
        {
            if (visited.size() > MAX_ENCLOSE)
                return Status::NENCLOSED;

            auto [curr_x, curr_y] = q.front();
            q.pop();
            for (auto &dir : dirs)
            {
                int n_x = curr_x + dir.first;
                int n_y = curr_y + dir.second;

                if (n_x == end.first && n_y == end.second)
                    return Status::MEET;

                if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= n)
                    continue;
                if (blocks.find({n_x, n_y}) != blocks.end())
                    continue;
                if (visited.find({n_x, n_y}) != visited.end())
                    continue;

                q.push({n_x, n_y});
                visited.insert({n_x, n_y});

            } //for
        }     //while
        return Status::ENCLOSED;
    }
};
// @lc code=end
