/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        // greedy:
        // sort all engineers by their efficent in de.
        // so for person[i], all the engineer before person[i] has greater efficiency
        // from them. pick the k max speed
        vector<pair<long long, long long>> persons;
        const long long M = 1e9 + 7;
        long long speedSum = 0;
        long long res = 0;

        for (int i = 0; i < n; i++)
            persons.push_back({efficiency[i], speed[i]});
        sort(persons.begin(), persons.end(), greater<>());

        priority_queue<int, vector<int>, greater<>> pq;

        for (int i = 0; i < n; i++)
        {
            speedSum += persons[i].second;
            pq.push(persons[i].second);

            if (pq.size() > k)
            {
                speedSum -= pq.top();
                pq.pop();
            }
            res = max(res, speedSum * persons[i].first);
        } //for
        return res % M;
    } //
};
// @lc code=end
