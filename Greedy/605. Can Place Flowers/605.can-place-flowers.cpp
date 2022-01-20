/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int i = 1;
        while (i < flowerbed.size() - 1)
        {
            if (flowerbed[i] == 1)
            {
                i += 2;
            }
            else
            {
                if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                ++i;
            }
        }
        return n <= 0;
    }
};

// @lc code=end
