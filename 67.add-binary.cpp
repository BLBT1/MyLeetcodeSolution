/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        // bit masking and shifting
        int i1 = a.size() - 1;
        int i2 = b.size() - 1;
        int carry = 0;
        int sum = 0;
        string res;
        while (i1 >= 0 || i2 >= 0 || carry > 0)
        {
            int n1 = i1 >= 0 ? a[i1] : 0;
            int n2 = i2 >= 0 ? b[i2] : 0;
            sum = n1 + n2 + carry;
            // &0b1 to mask the last bit
            int mask = 0b1;
            // mask out the last bit from the sum
            res.push_back((sum & mask) + '0');
            // mask out the second last bit from sum, it is carry
            carry = (sum >> 1) & mask;
            --i1;
            --i2;
        } //while
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
