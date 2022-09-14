class Solution
{
public:
    vector<long long> maximumEvenSplit(long long n)
    {
        if (n % 2 == 1)
            return {};

        vector<long long> res;
        long long i = 2;
        long long sum = 0;

        while (sum + i <= n)
        {
            res.push_back(i);
            sum += i;
            i += 2;
        }

        res.back() += n - sum;
        return res;
    }
};