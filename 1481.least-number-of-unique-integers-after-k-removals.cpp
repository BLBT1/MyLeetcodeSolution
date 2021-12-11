/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        // greedy + pq
        const int n = arr.size();
        int totalElts = 0;
        unordered_map<int, int> cnts;
        for (int i = 0; i < n; ++i)
        {
            cnts[arr[i]]++;
        } //for

        totalElts = cnts.size();

        // reverse key and val, put into a vector
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &p : cnts)
        {
            pq.push({p.second, p.first});
        } //for

        int numRemoval = 0;
        while (!pq.empty() && k > 0)
        {
            int cnt = pq.top().first;
            int ele = pq.top().second;
            pq.pop();
            if (k >= cnt)
            {
                k -= cnt;
                ++numRemoval;
            }
        } //while

        return totalElts - numRemoval;
    }
};
// @lc code=end

//  [5, 5, 4]
// given an arr and int k
// find least 3 of unique int after remove
// exact k element
// greedy??
//least # of unique -> remove most unique
// 4,3,1,2
// 1 3 2 1

// 4, 2, 1, 3
// 1, 1, 2, 3
