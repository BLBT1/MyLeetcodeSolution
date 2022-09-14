class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i)
            mp[arr[i]]++;
        priority_queue<int, vector<int>, less<>> pq;
        for (auto p : mp)
            pq.push(p.second);

        int remove = 0;
        while (remove < n / 2)
        {
            remove += pq.top();
            pq.pop();
        }

        return mp.size() - pq.size();
    }
};