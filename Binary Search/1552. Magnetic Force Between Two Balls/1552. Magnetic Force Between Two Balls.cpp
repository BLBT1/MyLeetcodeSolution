class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int l = 1;
        int r = 1e9 - 1;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (canPlaceAllBall(position, m, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    bool canPlaceAllBall(vector<int> &position, int m, int dist)
    {
        int n = position.size();
        int cnt = 1; // how many balls we can place
        // place one in first buckest
        int i = 0; // pos of last ball
        while (i < n)
        {
            // find pos of next ball
            int j = i;
            while (j < n && position[j] - position[i] < dist)
                ++j;
            if (j < n)
                cnt += 1;
            i = j;
        }
        return cnt >= m;
    }
};
// put two balls to make them as far as possible
// search the distance between two balls, see if we can put all the balls into position