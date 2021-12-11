/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        using PIV = pair<int, vector<int>>;

        const int m = mat.size();
        if (m == 0)
            return -1;

        const int n = mat[0].size();
        priority_queue<PIV, vector<PIV>, greater<>> pq; // smallest first

        //用一个set来去重，
        //因为vector本身是可排序的，必须用set，而不是unordered_set
        set<vector<int>> visited;

        //push in the seed
        int sum = 0;
        vector<int> pos; // index of each row
        pos.reserve(m);
        for (int i = 0; i < m; ++i)
        {
            sum += mat[i][0];
            pos.push_back(0);
        }
        visited.insert(pos);
        pq.push(make_pair(sum, pos));

        // do k time
        for (int counter = 0; counter < k; ++counter)
        {
            sum = pq.top().first;
            pos = pq.top().second;
            pq.pop();

            if (counter == k - 1)
                return sum;

            // push all the possible "a bit greater"
            for (int i = 0; i < m; i++)
            {
                pos[i]++;
                if (pos[i] < n && visited.find(pos) == visited.end())
                {
                    visited.insert(pos);
                    pq.push({sum + mat[i][pos[i]] - mat[i][pos[i] - 1], pos});
                }
                pos[i]--;
            }
        } //for

        return -1;
    }
};
// @lc code=end
