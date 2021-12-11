class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        // this is problem is topSort
        // step1. make the graph (adjacency list)
        unordered_map<char, set<char>> graph;
        unordered_map<char, int> inDeg;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                inDeg[words[i][j]] = 0;

        string res = "";

        // compare each adj words
        for (int i = 0; i < words.size() - 1; ++i)
        {
            string s = words[i];
            string t = words[i + 1];

            // if s in t and s is longer than t
            if (s.size() > t.size() && s.substr(0, t.size()) == t)
                return res;

            int len = min(s.size(), t.size());
            for (int j = 0; j < len; ++j)
            {
                if (s[j] == t[j])
                    continue;

                if (graph[s[j]].find(t[j]) == graph[s[j]].end())
                {
                    inDeg[t[j]]++;
                    graph[s[j]].insert(t[j]);
                }
                break;
            } //for
        }     //for

        // do topSort
        queue<char> q;

        for (auto &p : inDeg)
        {
            if (p.second == 0)
                q.push(p.first);
        }

        while (!q.empty())
        {
            char curr = q.front();
            q.pop();
            res.push_back(curr);

            //cout << curr << endl;

            for (auto next : graph[curr])
            {
                inDeg[next]--;
                if (inDeg[next] == 0)
                    q.push(next);
            }
        } //while

        if (res.size() == inDeg.size())
            return res;

        return "";
    }
};