class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        map<int, double> mp; // {pos, time}
        for (int i = 0; i < position.size(); ++i)
        {
            mp[-position[i]] = static_cast<double>((target - position[i])) / speed[i]; // sorted by the highest position
        }

        int res = 1;
        double prev = (*mp.begin()).second;
        for (auto p : mp)
        {
            if (p == *mp.begin())
                continue;

            if (prev < p.second)
            {
                res++;
                prev = p.second;
            }
        }
        return res;
    }
};