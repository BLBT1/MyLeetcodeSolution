/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        using PIC = pair<int, char>;
        string res;
        res.reserve(a + b);
        priority_queue<PIC, vector<PIC>, less<>> pq; // max heap

        pq.push({a, 'a'});
        pq.push({b, 'b'});

        while (!pq.empty())
        {
            if (pq.size() == 1)
            {
                int k = pq.top().first;
                if (k > 2)
                    return "";
                else
                {
                    for (int i = 0; i < k; i++)
                        res.push_back(pq.top().second);
                    return res;
                }
            }

            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            //
            int k = min(1 + x.first - y.first, 2);
            for (int i = 0; i < k; i++)
                res.push_back(x.second);
            res.push_back(y.second);

            x.first -= k;
            y.first -= 1;
            if (x.first != 0)
                pq.push(x);
            if (y.first != 0)
                pq.push(y);
        } //while

        return res;
    }
};
// @lc code=end
