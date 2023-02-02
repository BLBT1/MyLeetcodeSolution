class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        // O(NlogM) N is num of houses, M is num of heaters
        // regular binary search
        sort(heaters.begin(), heaters.end());

        int res = 0;
        // 遍历房子， 看每个房子到下一个heater的距离
        for (int i = 0; i < houses.size(); ++i)
        {
            int r;
            auto pos = lower_bound(heaters.begin(), heaters.end(), houses[i]);

            if (pos == heaters.begin())
                r = heaters[0] - houses[i];
            else if (pos == heaters.end())
                r = houses[i] - heaters.back();
            else
                r = min(*pos - houses[i], houses[i] - *(pos - 1));

            res = max(res, r);
        }
        return res;
    }
};