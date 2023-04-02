class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res(spells.size());
        for (int i = 0; i < spells.size(); ++i)
        {
            long long need = success % spells[i] == 0 ? success / spells[i] : success / spells[i] + 1;
            auto pos = lower_bound(potions.begin(), potions.end(), need);
            res[i] = potions.size() - (pos - potions.begin());
        }
        return res;
    }
};

// O(N*M) => 10^10
// sort + binary search => O(NlogM+MlogM) ~= 10^6