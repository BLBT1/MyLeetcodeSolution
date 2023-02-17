class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int l = 1;
        int r = 2e9;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            int cnt = cntSmallerEqual(mid, a, b, c);
            if (cnt < n)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    long long cntSmallerEqual(int mid, int a, int b, int c)
    {
        // inclusion-exclusion principal?
        long long A = mid / a;
        long long B = mid / b;
        long long C = mid / c;
        long long AB = mid / lcm(a, b);
        long long AC = mid / lcm(a, c);
        long long BC = mid / lcm(b, c);
        long long ABC = mid / lcm(a, lcm(b, c));
        return A + B + C - AB - BC - AC + ABC;
    }

    long long lcm(long long a, long long b)
    {
        return (a * b) / gcd(a, b);
    }
};
// lcm = (a,b) = a*b/gcd(a, b) (最小公倍数)

// 6
// A = 6/2 = 3 (2, 4, 6)
// B = 6/3 = 2 (3, 6)
// C = 6/4 = 1 (4)
// AB = 1
// AC = 0
// BC = 0
// ABC = 0
// 5