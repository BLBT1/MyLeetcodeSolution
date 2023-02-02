class Solution
{
public:
    string smallestGoodBase(string n)
    {
        // n = b^0+b^1...b^(k-1) = (b^k-1)/(b-1)
        long long N = stoll(n);
        // k 从大到小搜索，b就是从小到大 二分
        for (int k = log(N + 1) / log(2); k >= 2; --k)
        {
            long long low = 2;
            long long hi = pow(N, 1.0 / (k - 1));
            while (low <= hi)
            {
                long long mid = low + (hi - low) / 2;

                long long sum = 1;
                for (int i = 1; i <= k - 1; ++i)
                    sum = sum * mid + 1;

                if (sum == N)
                    return to_string(mid);
                else if (sum < N)
                    low = mid + 1;
                else if (sum > N)
                    hi = mid - 1;
            }
        }

        return to_string(N - 1);
    }
};