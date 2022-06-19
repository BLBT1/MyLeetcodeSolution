class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s; // monotonic increasing stack
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                if (!s.empty())
                {
                    int left = s.top();
                    res = max(res, (i - s.top() - 1) * h);
                }
                else
                {
                    // only one histgram in stack
                    res = max(res, (i + 1 - 1) * h);
                }
            }
            s.push(i);
        }

        // still has histgram in the stack
        int right = heights.size();
        while (!s.empty())
        {
            int h = heights[s.top()];
            s.pop();
            int left = s.empty() ? -1 : s.top();
            res = max(res, (right - left - 1) * h);
        }

        return res;
    }
};

// as long as increasing, then the curr rectangle can not the largest
//    => monotonic increasing
// 开始退栈后， 从右边开始找， 以 i 的高度为高，往左边最多能推多少
