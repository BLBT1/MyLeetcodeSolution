/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    //* solve in linear time and O(1) space
    int majorityElement(vector<int> &nums)
    {
        pair<int, int> NumCnt = make_pair(0, 0);
        //* the first pass to find majority
        for (auto &i : nums)
        {
            if (NumCnt.second == 0)
            {
                NumCnt.first = i;
                NumCnt.second = 1;
            }
            else
            {
                if (NumCnt.first == i)
                {
                    ++NumCnt.second;
                }
                else
                {
                    --NumCnt.second;
                }
            }
        }
        return NumCnt.first;
    } // majorityElement()
};
// @lc code=end
