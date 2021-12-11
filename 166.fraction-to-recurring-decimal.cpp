/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        int sign = 1;
        long a = numerator;
        long b = denominator;
        if (a < 0)
        {
            sign *= -1;
            a = abs(a);
        }
        if (b < 0)
        {
            sign *= -1;
            b = abs(b);
        }
        if (a == 0)
            return "0";
        string res;
        if (sign == -1)
            res.push_back('-');

        res += to_string(a / b);
        long c = a % b;
        if (c == 0)
            return res;

        unordered_map<int, int> map; // reminder, pos of digit
        res.push_back('.');
        while (c != 0 && map.find(c) == map.end())
        {
            map[c] = res.size();
            int digit = c * 10 / b;
            res.push_back(digit + '0');
            c = (c * 10) % b;
        }

        if (c == 0)
            return res;

        res.insert(res.begin() + map[c], '(');
        res.push_back(')');
        return res;
    }
};
// @lc code=end
