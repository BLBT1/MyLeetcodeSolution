class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int idx1 = convert(s);
        int idx2 = convert(t);
        // s[0, idx) is the converted string
        return s.substr(0, idx1) == t.substr(0, idx2);
    }

    // return the last valid idx of string
    int convert(string &s)
    {
        int i = 0, j = 0;
        for (; j < s.size(); ++j)
        {
            if (s[j] != '#')
            {
                s[i] = s[j];
                i++;
            }
            else
            {
                if (i > 0)
                    i--;
            }
        }
        return i;
    }
};

// "a c # c"
//      i
//        j