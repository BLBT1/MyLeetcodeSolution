/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n; // must inclusive on so not overflow the int
        int mid = l;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            int g = guess(mid);
            cout << g << endl;
            if (g < 0)
            {
                r = mid;
            }
            else if (g > 0)
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
        } //while
        return l;
    }
};
// @lc code=end

// 2  guess 1
// l = 1; r = 3
// mid == 2
// r = 2 l = 1;
// mid = 1
// 1 2
// l r
