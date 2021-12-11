/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

// @lc code=start
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int cnt = 0;
        int i = 1;
        for (; i <= n; ++i)
        {
            if (n % i == 0)
                cnt++;
            if (cnt == k)
                return i;
        }
        return -1;
    }
};
// @lc code=end
//two int(+) n , k
// i where n%i==0, than i is a factor of
//return kth factor in list

// n = 12, k =3
//1,2,3,4,6,12
// all factors are in the range of [1,n]
