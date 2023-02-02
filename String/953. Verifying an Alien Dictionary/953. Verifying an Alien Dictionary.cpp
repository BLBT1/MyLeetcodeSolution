class Solution
{
    unordered_map<char, int> order_mp;

public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < order.size(); ++i)
            order_mp[order[i]] = i;
        for (int i = 1; i < words.size(); ++i)
        {
            bool cmp = compWords(words[i - 1], words[i]);
            if (cmp == false)
                return false;
        }
        return true;
    }

    bool compWords(string &w1, string &w2)
    {
        int i = 0, j = 0;
        int m = w1.size();
        int n = w2.size();
        while (i < m && j < n)
        {
            if (order_mp[w1[i]] < order_mp[w2[j]])
                return true;
            else if (order_mp[w1[i]] > order_mp[w2[j]])
                return false;
            else
                ++i, ++j;
        }
        if (i == m)
            return true;
        return false;
    }
};

// O(N*S) => 100*20
// w1 w2 w3 ... wk
