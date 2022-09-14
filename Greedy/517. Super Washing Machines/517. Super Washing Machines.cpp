class Solution
{
public:
    int findMinMoves(vector<int> &machine)
    {
        int sum = accumulate(machine.begin(), machine.end(), 0);
        int n = machine.size();

        if (sum % n != 0)
            return -1;

        int avg = sum / n;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // left[i]+right[i] = machine[i]-avg
        // right[i] = left[i+1]

        left[0] = 0;
        right[n - 1] = 0;

        left[n - 1] = machine[n - 1] - avg;
        right[0] = machine[0] - avg;

        for (int i = 1; i < n - 1; ++i)
        {
            left[i] = -right[i - 1];
            right[i] = machine[i] - avg - left[i];
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int t = 0;
            if (right[i] > 0)
                t += right[i];
            if (left[i] > 0)
                t += left[i];
            res = max(res, t);
        }

        return res;
    }
};