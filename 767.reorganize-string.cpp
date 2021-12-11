/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string s)
    {
        // 此题有两种greedy思想：
        // 1. 隔开高频词，留空格来填低频词构造（快，但是不通用）
        // 2. 结合pq，先取高频词，这样剩余的char会更均匀，更有可能隔开（可以通用只k不同词）

        using PIC = pair<int, char>; // {freq,char}

        unordered_map<char, int> freq;
        for (auto ch : s)
            freq[ch]++;

        priority_queue<PIC, vector<PIC>, less<>> max_freq;

        for (auto &pic : freq)
            max_freq.push({pic.second, pic.first});

        // start constructing the res
        string res;
        res.reserve(s.size());
        while (!max_freq.empty())
        {
            int k = min((int)max_freq.size(), 2); // 每次取得个数

            if (k == 1 && max_freq.top().first > 1)
                return "";
            vector<PIC> temp;
            temp.reserve(k);
            for (int i = 0; i < k; ++i)
            {
                auto [freq, ch] = max_freq.top();
                max_freq.pop();
                freq--;
                res.push_back(ch);
                // store to temp vector
                if (freq > 0)
                    temp.push_back({freq, ch});
            } //for

            for (auto pic : temp)
                max_freq.push(pic);

        } //while

        return res;
    }
};
// @lc code=end
