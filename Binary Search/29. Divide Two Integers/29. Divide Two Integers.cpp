class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long a = (long)dividend;
        long b = (long)divisor;
        long sign = 1;
        if (a < 0)
            sign *= -1;
        if (b < 0)
            sign *= -1;
        a = abs(a);
        b = abs(b);

        long res = 0;
        while (a >= b)
        {
            long c = b;
            long cnt = 1;
            while ((c << 1) <= a)
            {
                c = c << 1;
                cnt = cnt << 1;
            }
            res += cnt;
            a -= c;
        }

        if (res * sign > INT_MAX)
            return INT_MAX;
        return sign * res;
    }
};

// 其实这个题是把除法转化成减法
// a/b => a - k*b
// 也就是从 1 开始猜测
// a-b
// a-2*b
// a-3*b
// ...
// a-k*b,
// where a-(k+1)*b < 0
// 这个思路是可以的，但是太慢了
// 所以我们可以用binary search的思路， 每次k放大2倍
// 也就是
// a-b
// a-2*b
// a-4*b
// ...
// a-2^w*b
// 如果2^(w+1)*b > a
// 那我们就 a_ = a - 2^w *b
// 然后a_继续尝试

// 这样时间复杂度是 (logn + log(n/2) + log(n/4) +.... +1) = (logN)^2
