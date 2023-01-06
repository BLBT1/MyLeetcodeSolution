class Solution {
    class mycomp
    {
        public:
            bool operator()(pair<int, int> &a, pair<int, int>&b)
            {
                if(a.second != b.second)
                    return a.second < b.second;

                return a.first >= b.first;
            }
    };
public:
    vector<int> topStudents(vector<string>& pf,
                            vector<string>& nf,
                            vector<string>& report,
                            vector<int>& id, int k) 
    {    
        unordered_set<string> pf_set(pf.begin(), pf.end());
        unordered_set<string> nf_set(nf.begin(), nf.end());
        unordered_map<int, int> scores;// id => score
        int n = report.size();
        for(int i = 0; i < n; ++i)
        {
            int j = 0;
            string comments = report[i] + " ";
            while(j < comments.size())
            {
                int k = comments.find(" ", j);
                string c = comments.substr(j, k-j);
                if(pf_set.find(c) != pf_set.end())
                    scores[id[i]] += 3;
                else if(nf_set.find(c) != nf_set.end())
                    scores[id[i]] -= 1;
                else
                    scores[id[i]] += 0;
                j = k+1;
            }
        }
        
        // quickselect can be used here
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> pq;
        for(auto p: scores)
            pq.push(p);
        
        vector<int> res;
        int cnt = 0;
        while(cnt < k)
        {
            res.push_back(pq.top().first);
            pq.pop();
            ++cnt;
        }
        
        return res;
    }
};