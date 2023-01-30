class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        long small = 0;
        long large = x;
        while (small < large)
        {
            long mid = small + (large - small + 1) / 2;
            if (mid <= x / mid)
                small = mid;
            else if (mid > x / mid)
                large = mid - 1;
        }
        return small;
    }
};

// 这个题目的本质是找一个int k，k是最后一个数 st. k*k <= x
// 以 8 为例子， 如果mid = 2，
// 我们看到 2*2 < 8, 2 还是有可能是答案的，
// 所以要保留在搜索区间里
// 看 3*3 > 8， 所以 3 肯定不是8的sqrt。
