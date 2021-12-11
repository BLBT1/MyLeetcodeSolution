/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt; // {num, cnt}
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
        for (auto &i : nums)
        {
            cnt[i]++;
        }

        for (auto &p : cnt)
        {
            pq.push({p.second, p.first});
        }

        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end
