class Solution
{
public:
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> next;
    unordered_map<string, unordered_set<string>> prev;
    vector<vector<string>> res;
    string beginWord;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // this problem is a combo of bfs and dfs
        // first use bfs to search (like problem 127) and record the prev for each step
        // than use dfs to find the resulting paths by prev

        // add the begin word into the wordList
        wordList.push_back(beginWord);

        // 1. construct wordSet for O(1) find
        for (auto str : wordList)
            wordSet.insert(str);
        this->beginWord = beginWord;

        if (wordSet.find(endWord) == wordSet.end())
            return {};

        // 2. construct a nextWords map
        for (int i = 0; i < wordList.size(); i++)
        {
            string str = wordList[i];
            for (int k = 0; k < str.size(); k++)
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string temp = str;
                    temp[k] = ch;
                    if (temp == str)
                        continue;
                    if (wordSet.find(temp) != wordSet.end())
                        next[str].push_back(temp);
                }
            }
        }

        // 3. do a bfs from beginWord to endWord
        unordered_set<string> visited;
        queue<string> q;
        int flag = 0;

        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty())
        {
            int len = q.size();
            unordered_set<string> newVisited;

            for (int k = 0; k < len; k++)
            {
                string str = q.front();
                q.pop();

                for (auto nextStr : next[str])
                {
                    if (visited.find(nextStr) != visited.end())
                        continue;
                    prev[nextStr].insert(str);
                    newVisited.insert(nextStr);

                    if (nextStr == endWord)
                        flag = 1;
                }
            }

            for (auto x : newVisited)
            {
                visited.insert(x);
                q.push(x);
            }

            if (flag == 1)
                break;
        }

        if (flag == 0)
            return {};

        // 4. use DFS and prev to find the res;
        DFS(endWord, {endWord});

        return res;
    }

    void DFS(string word, vector<string> path)
    {
        if (word == beginWord)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }

        for (auto preStr : prev[word])
        {
            vector<string> newPath = path;
            newPath.push_back(preStr);
            DFS(preStr, newPath);
        }
        return;
    }
};