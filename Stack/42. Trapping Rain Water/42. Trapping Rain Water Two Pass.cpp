class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // find LeftMost for all
        vector<int> leftMost(n);
        for (int i = 1; i < n; ++i)
            leftMost[i] = max(leftMost[i - 1], height[i - 1]);

        vector<int> rightMost(n);
        for (int j = n - 2; j >= 0; --j)
            rightMost[j] = max(rightMost[j + 1], height[j + 1]);

        int sum = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            sum += max(0, min(leftMost[i], rightMost[i]) - height[i]);
        }

        return sum;
    }
};

// sumForAllI(min(maxLeft, maxRight) - height[i])