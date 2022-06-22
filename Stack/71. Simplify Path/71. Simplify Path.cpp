class Solution
{
public:
    string simplifyPath(string path)
    {
        // first, split by '/'
        vector<string> strVec;
        int i = 0;
        while (i + 1 < path.size())
        {
            int j = path.find("/", i + 1);
            if (j == -1)
            {
                strVec.push_back(path.substr(i + 1));
                break;
            }
            else
            {
                strVec.push_back(path.substr(i + 1, j - i - 1));
                i = j;
            }
        }

        // using a vector to be a stack
        vector<string> s;
        // ".." => pop
        // "." => do nothing
        // else => push into stack
        for (auto &str : strVec)
        {
            if (str == "..")
            {
                if (!s.empty())
                    s.pop_back();
            }
            else if (str != "." && str != "")
            {
                s.push_back(str);
            }
        }

        string res = "";
        for (auto &str : s)
        {
            res.push_back('/');
            res += str;
        }
        return res == "" ? "/" : res;
    }
};
// given a absolute path => return a canonical path

// /home/