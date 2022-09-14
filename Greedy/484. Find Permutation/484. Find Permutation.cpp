class Solution
{
public:
    vector<int> findPermutation(string s)
    {
        int n = s.size();
        vector<int> res;
        stack<int> sk;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == 'I')
            {
                sk.push(i);
                while (!sk.empty())
                {
                    res.push_back(sk.top());
                    sk.pop();
                }
            }
            else
            {
                sk.push(i);
            }
        }

        sk.push(n + 1);
        while (!sk.empty())
        {
            res.push_back(sk.top());
            sk.pop();
        }

        return res;
    }
};