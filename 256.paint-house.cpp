class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int red = costs[0][0], blue = costs[0][1], green = costs[0][2];

        const int n = costs.size();
        for (int i = 1; i < n; ++i)
        {
            int old_red = red;
            int old_blue = blue;
            int old_green = green;

            red = min(old_blue, old_green) + costs[i][0];
            blue = min(old_green, old_red) + costs[i][1];
            green = min(old_red, old_blue) + costs[i][2];
        }

        return min(min(red, blue), green);
    }
};