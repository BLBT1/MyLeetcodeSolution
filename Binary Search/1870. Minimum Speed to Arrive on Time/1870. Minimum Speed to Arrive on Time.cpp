class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int low = 1;
        int hi = 1e7;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (canArrive(dist, hour, mid))
                hi = mid;
            else
                low = mid + 1;
        }
        return canArrive(dist, hour, low) ? low : -1;
    }

    bool canArrive(vector<int> &dist, double hour, int speed)
    {
        double sum = 0;
        for (int i = 0; i < dist.size(); ++i)
        {
            double d = dist[i];
            if (i != dist.size() - 1)
            {
                if ((int)d % speed != 0)
                    sum += (int)d / speed + 1.0;
                else
                    sum += (int)d / speed;
            }
            else
                sum += d / speed;
        }
        return sum <= hour;
    }
};