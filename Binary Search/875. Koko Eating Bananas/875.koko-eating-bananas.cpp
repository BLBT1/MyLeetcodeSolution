/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid;

        while (l < r)
        {
            mid = l + (r - l) / 2;

            if (canFinish(piles, h, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool canFinish(vector<int> &piles, int h, int k)
    {
        int sum = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            if (piles[i] % k == 0)
                sum += piles[i] / k;
            else
                sum += (piles[i] / k + 1);
        }
        return sum <= h;
    }
};

// min k so that koko can finish all piles
// koko can eat min(pile, k)
// come up a range than guess a number:
// min k = 1, max = max pile from piles
//

// day = 2

// [3, 2, 7, 11]
//     i

// l = 1
// r = 11
// mid = 6

// l = 1
// r = 6
// mid = 3

// l = 4
// r = 6
// mid = 5

// r = 5
// l = 4
// mid = 4

// r = 4
// l = 4
// mid = 4
// @lc code=end
