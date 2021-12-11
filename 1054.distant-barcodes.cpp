/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        using PII = pair<int, int>;

        unordered_map<int, int> freq; //{barcode,freq}
        for (auto &i : barcodes)
            freq[i]++;

        priority_queue<PII, vector<PII>, less<>> pq; // {frq , barcode}

        for (auto &pii : freq)
            pq.push({pii.second, pii.first});

        vector<int> res;
        res.reserve(barcodes.size());

        while (!pq.empty())
        {
            int k = min((int)pq.size(), 2);
            vector<PII> store;
            store.reserve(k);
            for (int i = 0; i < k; ++i)
            {
                auto [frq, barcode] = pq.top();
                pq.pop();
                res.push_back(barcode);
                --frq;
                if (frq > 0)
                    store.push_back({frq, barcode});
            } //for

            for (auto &x : store)
                pq.push(x);
        } //while

        return res;
    }
};
// @lc code=end
