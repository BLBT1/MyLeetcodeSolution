class Solution
{
public:
    string fractionToDecimal(int n, int d)
    {
        long a = n;
        long b = d;
        if (a == 0)
            return "0";

        // sign
        int sign = 1;
        if (a < 0)
        {
            a = abs(a);
            sign *= -1;
        }
        if (b < 0)
        {
            b = abs(b);
            sign *= -1;
        }

        string res = "";
        if (sign == -1)
            res.push_back('-');

        long c = a % b;
        res += to_string(a / b);
        if (c == 0)
            return res;

        res += ".";
        unordered_map<int, int> mp; // remainder => pos in res
        while (c != 0 && mp.find(c) == mp.end())
        {
            mp[c] = res.size();
            res.push_back('0' + (c * 10 / b));
            c = c * 10 % b;
        }

        if (c == 0)
            return res;

        res.insert(res.begin() + mp[c], '(');
        res.push_back(')');
        return res;
    }
};

ex : 1 / 7

    //      商  余
    // 1/7  0   1
    // 10/7 1   3
    // 30/7 4   2
    // 20/7 2   6
    // 60/7 8   4
    // 40/7 5   5
    // 50/7 7   1

    //  1/7 = "0.(142757)"