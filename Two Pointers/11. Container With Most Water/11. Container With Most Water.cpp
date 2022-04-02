class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max = (r - l) * min(height[l], height[r]);
        while (l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            if (area > max)
            {
                max = area;
            }
            int shorter = height[l] < height[r] ? l : r;
            if (shorter == l)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return max;
    }
};