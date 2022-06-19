class Solution
{
public:
    vector<int> findBuildings(vector<int> &heights)
    {
        // no next greater element
        stack<int> s; // decreasing stack
        vector<int> nextSmaller(heights.size(), -1);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] <= heights[i])
            {
                nextSmaller[s.top()] = heights[i];
                s.pop();
            }
            s.push(i);
        }

        vector<int> res;
        for (int i = 0; i < nextSmaller.size(); ++i)
        {
            if (nextSmaller[i] == -1) // no next greater
                res.push_back(i);
        }
        return res;
    }
};