/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        // my init thought, greedy on total students
        // better: use gain as key
        // gain = (pi+1)/(total+1) - pi/ti
        //*may be gain is not necessary to store
        //* write a comparator instead

        const int n = classes.size();
        typedef array<double, 3> PQEentry;

        priority_queue<PQEentry, vector<PQEentry>, less<>> pq;

        for (auto c : classes)
        {
            double p = c[0];
            double t = c[1];
            pq.push({(p + 1) / (t + 1) - p / t, p, t});
        } //for

        for (; extraStudents > 0; --extraStudents)
        {
            auto [r, p, t] = pq.top();
            pq.pop();
            p += 1;
            t += 1;
            pq.push({(p + 1) / (t + 1) - p / t, p, t});
        } //for

        double sum = 0;
        while (!pq.empty())
        {
            auto [r, p, t] = pq.top();
            sum += p / t;
            pq.pop();
        }

        return sum / n;
    }
};
// @lc code=end
