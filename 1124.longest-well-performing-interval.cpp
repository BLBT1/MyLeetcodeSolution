/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 */

// @lc code=start
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        // 使用单调栈和前缀和

        const int n = hours.size();
        int res = 0;

        //use a vector convert the problem to presum
        // tiring day -> 1
        // non tiring day -> -1
        vector<int> presum;
        presum.reserve(n + 1);
        presum.push_back(0); // add one extra 0
        int sum = 0;         // accumulate presum

        for (const auto hr : hours)
        {
            if (hr > 8)
            {
                sum += 1;
                presum.push_back(sum);
            }
            else
            {
                sum += -1;
                presum.push_back(sum);
            }
        }

        stack<int> Stack; // pos, mono de.
        for (int i = 0; i < presum.size(); ++i)
        {
            if (Stack.empty() || presum[Stack.top()] > presum[i])
                Stack.push(i);
        } //for

        for (int j = presum.size() - 1; j >= 0; --j)
        {
            while (!Stack.empty() && presum[Stack.top()] < presum[j])
            {
                res = max(res, j - Stack.top());
                Stack.pop();
            } //while
        }     //for

        return res;
    }
};
// @lc code=end
