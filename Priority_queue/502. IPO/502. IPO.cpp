class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int currCap = w;
        int n = profits.size();
        vector<pair<int, int>> projects; // {profit[i], capital[i]}
        for (int i = 0; i < n; ++i)
            projects.push_back({capital[i], profits[i]});

        sort(projects.begin(), projects.end()); // sort by capital
        int i = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
        int cnt = 0; // how many project have we done
        while (i < n || !pq.empty())
        {
            int j = i;
            while (j < n && projects[j].first <= currCap)
            {
                pq.push({projects[j].second, projects[j].first});
                ++j;
            }
            i = j;

            // do the project with the highest project;
            if (pq.empty())
                break;
            if (cnt >= k)
                break;
            currCap += pq.top().first;
            pq.pop();
            cnt += 1;
        }
        return currCap;
    }
};

// for each time, we want to find the project with highest project that we have enough capital to start;
//  - sort all project by their capital, use a pq for max profit