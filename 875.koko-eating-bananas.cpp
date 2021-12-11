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
        //* cannot use max as it only compare between two
        int r = *std::max_element(piles.begin(), piles.end()) + 1;
        int mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (can_eat_all(piles, h, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    bool can_eat_all(const vector<int> &piles, int h, int k)
    {
        int h_ = 0;
        for (const auto &pile : piles)
        {
            h_ += (pile + k - 1) / k;
        }
        return h_ <= h;
    }
};
// @lc code=end
