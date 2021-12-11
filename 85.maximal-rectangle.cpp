/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        const int n = matrix.size();
        if (n == 0)
            return 0;
        const int m = matrix[0].size();

        if (m == 0)
            return 0;

        int res = 0;
        vector<int> hist(m, 0);

        // n * m matrix
        //* determine a lower bound, smash into a hist, and then use 084 method
        for (int lower = 0; lower < n; ++lower)
        {
            for (int row = 0; row < m; ++row)
            {
                // if 0  in the bottom, then not a hist, make entire col to 0;
                if (matrix[lower][row] == '1')
                {
                    hist[row] += 1;
                }
                else
                {
                    hist[row] = 0;
                }
            } //for
            //update the res
            res = max(res, findMaxRectFromHist(hist));
        } //for

        return res;
    }

    // 084
    int findMaxRectFromHist(vector<int> &hist)
    {
        if (hist.size() == 0)
            return 0;

        if (hist.size() == 1)
            return hist[0];

        int res = hist[0];

        // why?
        hist.insert(hist.begin(), 0);
        stack<int> Stack; // mono, in.
        hist.push_back(0);
        Stack.push(0);

        for (int i = 1; i < hist.size(); ++i)
        {
            while (hist[i] < hist[Stack.top()])
            {
                int h = hist[Stack.top()];
                Stack.pop();
                int w = i - Stack.top() - 1;
                res = max(res, h * w);
            } //while

            Stack.push(i);
        } //for

        hist.pop_back();
        hist.erase(hist.begin(), hist.begin() + 1);

        return res;
    }
};
// @lc code=end
