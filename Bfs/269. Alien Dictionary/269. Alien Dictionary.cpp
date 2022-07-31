class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        unordered_map<char, unordered_set<char>> mp;

        unordered_map<char, int> indegree;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                indegree[words[i][j]] = 0;

        for (int i = 1; i < words.size(); i++)
        {
            string word1 = words[i - 1];
            string word2 = words[i];

            // shorter word should be high in order
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";

            for (int i = 0; i < min(word1.size(), word2.size()); i++)
            {
                if (word1[i] == word2[i])
                    continue;
                if (mp[word1[i]].find(word2[i]) == mp[word1[i]].end())
                {
                    mp[word1[i]].insert(word2[i]);
                    indegree[word2[i]]++;
                }
                break;
            }
        }

        queue<char> q;
        string res = "";
        for (auto p : indegree)
        {
            if (p.second == 0)
            {
                q.push(p.first);
                res.push_back(p.first);
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (auto next : mp[curr])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                    res.push_back(next);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};