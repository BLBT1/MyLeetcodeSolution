/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        using PIC = pair<int, char>;

        string res;
        res.reserve(a + b + c);
        priority_queue<PIC> pq; // max heap

        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        while (!pq.empty())
        {
            if (pq.size() >= 2)
            {
                auto [f_x, ch_x] = pq.top();
                pq.pop();
                auto [f_y, ch_y] = pq.top();
                pq.pop();

                int k = min(2, f_x - f_y + 1);

                for (int i = 0; i < k; ++i)
                    res.push_back(ch_x);
                res.push_back(ch_y);

                if (f_x - k > 0)
                    pq.push({f_x - k, ch_x});
                if (f_y - 1 > 0)
                    pq.push({f_y - 1, ch_y});
            } //if
            else
            {
                auto [f_x, ch_x] = pq.top();
                int k = min(f_x, 2);
                for (int i = 0; i < k; ++i)
                    res.push_back(ch_x);
                pq.pop();
            }
        } //while

        return res;
    }
};
// @lc code=end
