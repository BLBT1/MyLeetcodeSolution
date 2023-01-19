class Solution
{
    vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

public:
    string intToRoman(int num)
    {
        string res;
        while (num != 0)
        {
            for (int i = 0; i < 13; ++i)
            {
                if (num / val[i] >= 1)
                {
                    int t = num / val[i];
                    num -= t * val[i];
                    for (int k = 0; k < t; ++k)
                        res += sym[i];
                    break;
                }
            }
        }
        return res;
    }
};
