class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<bool> vec(n + 1, false);
        for (int i = 2; i <= sqrt(n + 1); ++i)
        {
            if (vec[i] == true)
                continue;
            int j = 2;
            while (j * i < n + 1)
            {
                vec[j * i] = true;
                ++j;
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (vec[i] == false)
                cnt++;

        return cnt;
    }
};