/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<>> pq;
        for (auto &i : stones)
        {
            pq.push(i);
        }
        while (pq.size() > 1)
        {
            auto y = pq.top();
            pq.pop();
            auto x = pq.top();
            pq.pop();
            if (y - x != 0)
                pq.push(y - x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

// [1,1,2,4,7,8]
// @lc code=end
