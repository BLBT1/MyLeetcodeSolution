/*
 * @lc app=leetcode id=1882 lang=cpp
 *
 * [1882] Process Tasks Using Servers
 */

// @lc code=start
class Solution
{

public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        // * my intial thought, server_pq use {timefree, w, id} + diy comp
        //* the problem:
        //* 如果有若干个空闲机器的可开工时间不同、且都早于当前时刻时，
        //* 他们并不能重新按照权重排序（依然按照可开开工时间排序)

        //* should do:把空闲服务器和繁忙服务器分开来处理
        typedef array<int, 2> freeEntry;
        typedef array<int, 3> busyEntry;

        priority_queue<freeEntry, vector<freeEntry>, greater<>> FreePQ;
        priority_queue<busyEntry, vector<busyEntry>, greater<>> BusyPQ;

        queue<int> task_q;
        vector<int> res;
        res.reserve(tasks.size());

        for (int i = 0; i < servers.size(); i++)
            FreePQ.push({servers[i], i});

        // not stop either task in queue or in given list
        for (int j = 0; j < tasks.size(); j++)
        {
            if (j < tasks.size())
                task_q.push(j);

            // if some servers in busy pq ready to work
            // move to free pq
            while (!BusyPQ.empty() && BusyPQ.top()[0] <= j)
            {
                auto [t, w, idx] = BusyPQ.top();
                BusyPQ.pop();
                FreePQ.push({w, idx});
            } //while

            // in free pq, we don't care about time, they all free
            while (!task_q.empty() && !FreePQ.empty())
            {
                int taskID = task_q.front();
                task_q.pop();
                auto [w, idx] = FreePQ.top();
                FreePQ.pop();
                res.push_back(idx);
                BusyPQ.push({j + tasks[taskID], w, idx});
            } //while
        }     //for

        //* if still task waiting in q
        //* directly use busy as the time now bounded by busy queue
        while (!task_q.empty())
        {
            int taskID = task_q.front();
            task_q.pop();
            auto [t, w, idx] = BusyPQ.top();
            BusyPQ.pop();
            res.push_back(idx);
            BusyPQ.push({t + tasks[taskID], w, idx});
        }

        return res;
    }
};
// @lc code=end
