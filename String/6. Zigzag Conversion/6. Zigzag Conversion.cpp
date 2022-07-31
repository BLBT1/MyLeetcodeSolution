class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> zig(numRows, "");
        int i = 0;
        while (i < s.size())
        {
            // from up to down
            int currRow = 0;
            while (currRow < numRows && i < s.size())
            {
                zig[currRow].push_back(s[i]);
                ++i;
                ++currRow;
            }

            currRow -= 2;

            // from bottom up
            while (currRow > 0 && i < s.size())
            {
                zig[currRow].push_back(s[i]);
                ++i;
                --currRow;
            }
        }

        string res = "";
        for (auto str : zig)
            res += str;
        return res;
    }
};