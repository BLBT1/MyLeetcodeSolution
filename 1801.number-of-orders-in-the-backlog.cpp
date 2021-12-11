/*
 * @lc app=leetcode id=1801 lang=cpp
 *
 * [1801] Number of Orders in the Backlog
 */

// @lc code=start
class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, less<>> buy_pq; //{price,amount}
        priority_queue<PII, vector<PII>, greater<>> sell_pq;

        long res = 0;
        const long M = 1e9 + 7;

        for (int i = 0; i < orders.size(); ++i)
        {
            int p = orders[i][0];
            int n = orders[i][1];

            res = (res + n) % M;

            if (orders[i][2] == 0)
            {
                while (!sell_pq.empty() && sell_pq.top().first <= p && n > 0)
                {
                    auto [price, amount] = sell_pq.top();
                    sell_pq.pop();
                    long num = min((long)amount, (long)n);
                    amount -= num;
                    n -= num;
                    res = (res - num * 2 + M) % M;
                    if (amount > 0)
                        sell_pq.push({price, amount});
                } //while

                if (n > 0)
                    buy_pq.push({p, n});
            } //if
            else
            {
                while (!buy_pq.empty() && buy_pq.top().first >= p && n > 0)
                {
                    auto [price, amount] = buy_pq.top();
                    buy_pq.pop();
                    long num = min((long)amount, (long)n);
                    amount -= num;
                    n -= num;
                    res = (res - num * 2 + M) % M;
                    if (amount > 0)
                        buy_pq.push({price, amount});
                } //while
                if (n > 0)
                    sell_pq.push({p, n});
            } //else
        }     //for

        return res % M;
    }
};
// @lc code=end
