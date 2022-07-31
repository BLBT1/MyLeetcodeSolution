/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution
{
    // 0->up, 1->right, 2->down, 3->left
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<string> visited;

public:
    void cleanRoom(Robot &robot)
    {
        dfs(0, 0, 0, robot);
    }

    void dfs(int x, int y, int currDir, Robot &r)
    {
        r.clean();
        visited.insert(to_string(x) + " " + to_string(y));

        for (int k = 0; k < 4; ++k)
        {
            int nextDir = (currDir + k) % 4;
            int nextX = x + dir[nextDir].first;
            int nextY = y + dir[nextDir].second;

            if (visited.find(to_string(nextX) + " " + to_string(nextY)) == visited.end() && r.move())
            {
                dfs(nextX, nextY, nextDir, r);
                r.turnRight();
                r.turnRight();
                r.move();
                r.turnRight();
                r.turnRight();
            }
            r.turnRight();
        }
    }
};