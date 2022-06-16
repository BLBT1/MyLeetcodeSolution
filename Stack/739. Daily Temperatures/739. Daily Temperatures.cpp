class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        vector<int> res(t.size());
        stack<int> s; // record the index, not the val
        for (int i = t.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && t[s.top()] <= t[i])
                s.pop();
            if (s.empty())
                res[i] = 0;
            else
                res[i] = s.top() - i;
            s.push(i);
        }
        return res;
    }
};