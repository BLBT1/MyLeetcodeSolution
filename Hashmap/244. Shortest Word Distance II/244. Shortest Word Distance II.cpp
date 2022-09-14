class WordDistance
{
    unordered_map<string, vector<int>> mp;

public:
    WordDistance(vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2)
    {
        int m = mp[word1].size();
        int n = mp[word2].size();
        int res = INT_MAX;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            int dist = abs(mp[word1][i] - mp[word2][j]);
            res = min(res, dist);
            if (mp[word1][i] <= mp[word2][j])
                ++i;
            else
                ++j;
        }

        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
