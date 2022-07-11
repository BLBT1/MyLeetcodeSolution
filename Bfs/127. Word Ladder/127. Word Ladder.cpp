class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> visited;
        unordered_set<string> set(wordList.begin(), wordList.end());
        for (int i = 0; i < wordList.size(); i++)
        {
            visited[wordList[i]] = false;
        }

        // so that the end can be added to adj
        wordList.push_back(beginWord);

        // construct the graph
        for (int i = 0; i < wordList.size(); i++)
        {
            string s = wordList[i];
            for (int pos = 0; pos < s.size(); pos++)
            {
                string t = s;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (ch == s[pos])
                        continue;
                    t[pos] = ch;
                    if (set.find(t) != set.end())
                        adj[s].push_back(t);
                }
            }
        }

        // bfs
        queue<string> q;
        q.push(beginWord);
        int step = 1;

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                string curr = q.front();
                q.pop();
                for (auto &next : adj[curr])
                {
                    if (visited[next])
                        continue;
                    if (next == endWord)
                        return step + 1;
                    visited[next] = true;
                    q.push(next);
                }
            }
            step++;
        }
        return 0;
    }
};