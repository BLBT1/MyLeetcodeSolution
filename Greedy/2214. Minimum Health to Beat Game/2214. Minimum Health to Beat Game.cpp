class Solution
{
public:
    long long minimumHealth(vector<int> &damage, int armor)
    {
        int n = damage.size();
        long long mx = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            mx = max(static_cast<long long>(damage[i]), mx);
            sum += damage[i];
        }
        sum -= min(mx, static_cast<long long>(armor));
        return sum + 1;
    }
};