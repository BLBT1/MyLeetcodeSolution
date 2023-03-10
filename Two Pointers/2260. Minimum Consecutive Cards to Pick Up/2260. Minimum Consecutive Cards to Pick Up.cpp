class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> pos;
        int res = INT_MAX;
        int j = 0;
        int i = 0;
        for (; j < cards.size(); ++j)
        {
            if (pos.find(cards[j]) != pos.end())
            {
                res = min(j - pos[cards[j]] + 1, res);
                i++;
            }
            pos[cards[j]] = j;
        }
        return res == INT_MAX ? -1 : res;
    }
};

// find closet dist for a equal card
// subarray by element

// find smallest window with duplicate element