class Solution
{
public:
    string removeKdigits(string nums, int k)
    {
        stack<char> s;
        if (k >= nums.size())
            return "0";
        for (int i = 0; i < nums.size(); ++i)
        {
            while (k > 0 && !s.empty() && s.top() > nums[i])
            {
                k--;
                s.pop();
            }
            s.push(nums[i]);
        }

        while (k > 0)
        {
            s.pop();
            k--;
        }

        string res = "";
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        // remove top 0s
        while (res.back() == '0')
            res.pop_back();
        if (res.empty())
            res = "0";
        reverse(res.begin(), res.end());
        return res;
    }
};

// 1432219
// cnt = 1
// 1219