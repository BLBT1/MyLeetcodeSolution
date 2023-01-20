class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c < 0)
            return false;
        int r = sqrt(c);
        int l = 0;
        while (l <= r)
        {
            long long curr = (long long)l * (long long)l + (long long)r * (long long)r;
            if (curr > (long long)c)
                r -= 1;
            else if (curr < (long long)c)
                l += 1;
            else
                return true;
        }
        return false;
    }
};
