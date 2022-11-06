class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k >= 2)
        {
            sort(s.begin(), s.end());
            return s;
        }

        string res = s;
        for (int i = 0; i < s.size(); ++i)
        {
            string rot = s.substr(1) + s.substr(0, 1);
            if (rot < res)
                res = rot;
            s = rot;
        }
        return res;
    }
};