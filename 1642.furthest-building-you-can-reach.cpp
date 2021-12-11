class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int count = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        // start from building 0
        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > heights[i - 1])
            {
                pq.push(heights[i] - heights[i - 1]);
                if (count < ladders)
                {
                    ++count;
                }
                else
                {
                    if (!pq.empty() && bricks < pq.top())
                    {
                        // we cannot keep going
                        return i - 1;
                    }

                    bricks -= pq.top();
                    pq.pop();
                } //else
            }     //if
        }         //for

        return heights.size() - 1;
    }
};