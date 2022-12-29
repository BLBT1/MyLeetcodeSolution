class Solution {
    class mycmp
    {
        public:
            bool operator()(const vector<int> &a,const vector<int> &b)
            {
                if(a[1] != b[1])
                    return a[1] > b[1];
                return a[2] > b[2];
            }
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        const int n = tasks.size();
        long time = LONG_MAX;
        for(int i = 0; i < n; ++i)
        {
            // find the time for the first task to start
            if(tasks[i][0] < time)
            {
                time = tasks[i][0];
            }
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, mycmp> pq;
        vector<int> res;
        int i = 0;
        while(i < n || !pq.empty())
        {
            while(i < n && tasks[i][0] <= time)
            {
                pq.push(tasks[i]);
                ++i;
            }
            if(!pq.empty())
            {
                auto curr = pq.top();
                pq.pop();
                time += curr[1];
                res.push_back(curr[2]);                
            }
            else
            {
                // cpu will idle until the next task come in
                time = tasks[i][0];
            }
        }
        
        return res;
    }
};