/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */

// @lc code=start
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        // huahua's solution
        /* 
        *  ans can be large, so we return the mod 10e9+7 
        *  0 <= arr[i] <= 100
        * so we can use a vector to 
        *  count the occurance and avoid the overhead of hashtable
        * 
        */
        constexpr int MOD_NUM = 1e9 + 7;
        constexpr int MAX_ELEMENT = 100;
        long ans = 0;

        //* a vector to count, 0~100
        vector<long> count_num;
        count_num.resize(MAX_ELEMENT + 1);
        for (const auto &i : arr)
            ++count_num[i];

        //* use combanatorics to help
        for (int i = 0; i <= target; ++i)
        {
            for (int j = i; j <= target; ++j)
            {
                const int k = target - i - j;
                if (k < 0 || k >= count_num.size() || k < j)
                    continue;
                if (!count_num[i] || !count_num[j] || !count_num[k])
                    continue;

                //* four cases
                if (i == j && j == k)
                    ans += (count_num[i] - 2) * (count_num[i] - 1) * count_num[i] / 6;
                else if (i == j && j != k)
                    ans += count_num[i] * (count_num[i] - 1) / 2 * count_num[k];
                else if (i != j && j == k)
                    ans += count_num[i] * (count_num[j] - 1) * count_num[j] / 2;
                else
                    ans += count_num[i] * count_num[j] * count_num[k];
            } //for
        }     // for
        return ans % MOD_NUM;
    }
};
// @lc code=end
