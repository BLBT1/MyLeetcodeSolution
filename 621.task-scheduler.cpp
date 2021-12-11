/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        //using PIC = pair<int, char>;
        unordered_map<char, int> frq;
        int time = 0;

        for (char c : tasks)
            frq[c]++;

        priority_queue<int, vector<int>, less<>> pq; // max_heap

        for (auto &pic : frq)
            pq.push({pic.second});

        while (!pq.empty())
        {
            int k = n + 1;

            if (pq.top() == 1)
                return time + (int)pq.size();

            vector<int> temp;
            temp.reserve(k);
            for (int i = 0; i < k; ++i)
            {
                if (!pq.empty())
                {
                    auto f = pq.top();
                    pq.pop();
                    ++time;
                    --f;
                    if (f > 0)
                        temp.push_back(f);
                }
                else
                    ++time;
            } //for

            for (auto &pic : temp)
                pq.push(pic);
        } //while

        return time;
    }
};
// @lc code=end
