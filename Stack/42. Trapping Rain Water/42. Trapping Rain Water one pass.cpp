class Solution
{
public:
    int trap(vector<int> &height)
    {
        // one pass using decreasing stack
        stack<int> s;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            while (!s.empty() && height[s.top()] < height[i])
            {
                int base = height[s.top()];
                s.pop();
                if (!s.empty())
                {
                    int h = min(height[s.top()], height[i]);
                    int w = i - s.top() - 1;
                    sum += max(h - base, 0) * w;
                }
            }
            s.push(i);
        }
        return sum;
    }
};

// *  *
// ** *
// ****

// the second in stack is the left, i is the right