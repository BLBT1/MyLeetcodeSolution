class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int, vector<int>, less<>> pq;
        for (auto i : piles)
        {
            pq.push(i);
        }
        for (int i = 0; i < k; ++i)
        {
            auto x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
        }
        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};