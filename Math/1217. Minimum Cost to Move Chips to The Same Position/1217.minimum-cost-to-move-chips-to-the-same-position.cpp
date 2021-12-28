/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int numEven = 0;
        int numOdd = 0;
        for (int i = 0; i < position.size(); ++i)
        {
            if (position[i] % 2 == 1)
                numOdd++;
            else
                numEven++;
        }
        return min(numEven, numOdd);
    }
};
// @lc code=end
