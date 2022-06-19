class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        // next greater element?
        stack<int> s; // from right to left, monotonic decreasing
        vector<int> res(heights.size(), 0);
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && heights[s.top()] < heights[i])
            {
                res[i]++;
                s.pop();
            }
            // if stack is not empty, i can see one more
            if (!s.empty())
                res[i]++;
            s.push(i);
        }
        return res;
    }
};