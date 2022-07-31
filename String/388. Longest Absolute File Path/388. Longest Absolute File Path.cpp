class Solution
{
public:
    int lengthLongestPath(string s)
    {
        int n = s.size();
        vector<string> files;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j < n && s[j] != '\n')
                ++j;
            files.push_back(s.substr(i, j - i));
            i = j;
        }

        int res = 0;
        vector<string> paths;
        for (auto f : files)
        {
            // number of \t is the level of the current file
            int level = 0;
            int j = 0;
            while (f[j] == '\t')
            {
                j++;
                level++;
            }

            if (paths.size() < level + 1)
                paths.resize(level + 1);
            paths[level] = f.substr(level);

            if (f.find(".") != -1)
            {
                int sum = 0;
                for (int i = 0; i <= level; ++i)
                {
                    sum += paths[i].size();
                }
                sum += level; // numbers of "/"
                res = max(res, sum);
            }
        }
        return res;
    }
};