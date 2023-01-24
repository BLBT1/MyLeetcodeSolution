class Solution
{
    string s;
    vector<string> res;

public:
    vector<string> restoreIpAddresses(string s)
    {
        this->s = s;
        string currStr;
        int curr;
        // curr is the curr index we are looking at
        // remain is how many numbers do we still need
        dfs(0, 4, currStr);
        return res;
    }

    void dfs(int curr, int remain, string currStr)
    {
        if (remain == 0)
        {
            if (curr == s.size())
                res.push_back(currStr);
            return;
        }

        for (int i = 1; i <= 3; ++i)
        {
            if (curr + i > s.size())
                break;

            string t = s.substr(curr, i);

            // 1.01.XXX.XXX is not valid
            if (t[0] == '0' && t.size() > 1)
                break;

            int num = stoi(t);
            if (num > 255)
                continue;

            dfs(curr + i, remain - 1, (remain == 1) ? currStr + t : currStr + t + ".");
        }
    }
};