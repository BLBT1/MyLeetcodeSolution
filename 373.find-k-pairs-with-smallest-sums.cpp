/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b) const
        {
            return a.first >= b.first;
        } //operator()()
    };

    vector<vector<int>>
    kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        // construct a mat with all the sum
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int m = nums1.size();
        int n = nums2.size();

        k = min(k, m * n);

        vector<vector<int>> res;
        res.reserve(k);

        auto visited = vector<vector<int>>(m, vector<int>(n, 0));
        q.push({nums1[0] + nums2[0], 0});
        visited[0][0] = 1;

        int count = 0, i = 0, j = 0;
        while (count < k)
        {
            i = q.top().second / n;
            j = q.top().second % n;
            res.push_back({nums1[i], nums2[j]});
            count++;
            q.pop();

            if (i + 1 < m && visited[i + 1][j] == 0)
            {
                q.push({nums1[i + 1] + nums2[j], (i + 1) * n + j});
                visited[i + 1][j] = 1;
            }
            if (j + 1 < n && visited[i][j + 1] == 0)
            {
                q.push({nums1[i] + nums2[j + 1], (i)*n + j + 1});
                visited[i][j + 1] = 1;
            }
        }

        return res;
    }
};
// @lc code=end
