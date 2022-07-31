class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;

        for (auto i : nums)
        {
            mp[digSum(i)].push_back(i);
        }

        int res = -1;
        for (auto p : mp)
        {
            if (p.second.size() < 2)
                continue;
            int n = p.second.size();
            sort(p.second.begin(), p.second.end());
            res = max(res, p.second[n - 1] + p.second[n - 2]);
        }
        return res;
    }

    int digSum(int a)
    {
        int sum = 0;
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }
};
