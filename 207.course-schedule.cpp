/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // construct a map for indegree of each vertex
        vector<vector<int>> next(numCourses); // course to next course
        vector<int> inDegree(numCourses, 0);  // indegree of ith course
        for (auto &pre : prerequisites)       // you must take course b to take course a
        {
            next[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        } //for

        // normal bfs
        queue<int> q;
        int count = 0;
        // add all courses with no pre
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        } //for

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto c : next[curr])
            {
                inDegree[c]--;
                if (inDegree[c] == 0)
                {
                    q.push(c);
                    count++;
                }

            } //for
        }     //while

        return count == numCourses;
    }
};
// @lc code=end
