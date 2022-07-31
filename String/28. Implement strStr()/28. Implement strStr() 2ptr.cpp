class Solution
{
public:
    int strStr(string a, string b)
    {
        int i = 0, j = 0;
        while (i < a.size())
        {
            int i0 = i;
            while (i < a.size() && j < b.size() && a[i] == b[j])
            {
                i++;
                j++;
            }
            if (j == b.size())
                return i0;
            else
            {
                i = i0 + 1;
                j = 0;
            }
        }
        return -1;
    }
};