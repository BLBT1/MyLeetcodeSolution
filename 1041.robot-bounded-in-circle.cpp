/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        // N:(0,1), S(0,-1), w(-1,0), E(1,0)
        pair<int, int> dir = {0, 1}; //{x,y}
        pair<int, int> pos = {0, 0}; // pos from origin
        for (auto ch : instructions)
        {
            if (ch == 'G')
            {
                pos.first += dir.first;
                pos.second += dir.second;
            }
            else if (ch == 'L')
            {
                auto prev = dir;
                dir.first = -prev.second;
                dir.second = prev.first;
            }
            else
            {
                auto prev = dir;
                dir.first = prev.second;
                dir.second = -prev.first;
            }
        } //for
        // two cases that will form a cycle
        // case 1: if the robot return back to origin
        // case 2: if the robot has dir that is not point to north
        if (pos.first == 0 && pos.second == 0)
            return true;
        else if (dir.first != 0 || dir.second != 1)
            return true;
        return false;
    }
};
// @lc code=end

// (0,1) -> (-1, 0)
// (0,1) -> (1, 0)
//O(n), n is the size of string