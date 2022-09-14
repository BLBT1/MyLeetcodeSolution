class Solution
{
public:
    int findMinDifference(vector<string> &tp)
    {
        vector<int> mins;
        for (auto t : tp)
        {
            int min = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
            mins.push_back(min);
        }

        sort(mins.begin(), mins.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < mins.size(); ++i)
        {
            int diff = mins[i] - mins[i - 1];
            diff = min(diff, 60 * 24 - diff);
            minDiff = min(minDiff, diff);
        }

        int diff = abs(mins.back() - mins.front());
        diff = min(diff, 60 * 24 - diff);
        minDiff = min(minDiff, diff);

        return minDiff;
    }
};