class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int x = get_sqrt(num);
        return x * x == num;
    }

    int get_sqrt(int num)
    {
        if (num == 1)
            return 1;
        long l = 0, r = num;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (mid <= num / mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};