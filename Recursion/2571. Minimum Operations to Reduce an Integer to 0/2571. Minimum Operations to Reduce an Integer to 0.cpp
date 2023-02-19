class Solution
{
    set<int> power2;

public:
    int minOperations(int n)
    {
        int i = 1;
        while (i <= 2 * n)
        {
            power2.insert(i);
            i = i * 2;
        }
        return helper(n, power2);
    }

    int helper(int n, set<int> &power2)
    {
        if (n == 0)
            return 0;
        if (power2.find(n) != power2.end())
            return 1;
        auto pos = upper_bound(power2.begin(), power2.end(), n);
        int bigger = *pos;
        int smaller = bigger / 2;
        int s_diff = n - smaller;
        int b_diff = bigger - n;
        return min(helper(s_diff, power2), helper(b_diff, power2)) + 1;
    }
};