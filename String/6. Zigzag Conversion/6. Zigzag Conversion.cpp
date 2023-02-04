class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        vector<string> res(numRows, "");
        int i = 0;
        while (i < n)
        {
            for (int j = 0; j < numRows; ++j)
            {
                if (i >= n)
                    break;
                res[j].push_back(s[i]);
                ++i;
            }
            for (int k = numRows - 2; k >= 1; --k)
            {
                if (i >= n)
                    break;
                res[k].push_back(s[i]);
                ++i;
            }
        }

        string ans;
        for (auto r : res)
            ans += r;
        return ans;
    }
};

// P
// A
// Y
// // P
// 3
// "PAYPALISHIRING"

// p
// A
// Y
