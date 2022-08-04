class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int res = 0;
        for (auto p : points)
        {
            map<pair<int, int>, int> mp;
            int v = 0; // for all pts in the vertical(dx == 0)
            for (auto q : points)
            {
                if (p == q)
                    continue;

                int dx = q[0] - p[0];
                int dy = q[1] - p[1];

                if (dx == 0)
                {
                    v++;
                    continue;
                }

                int a = dy / (gcd(dx, dy));
                int b = dx / (gcd(dx, dy));
                mp[make_pair(a, b)]++;
            }

            res = max(1, res);
            res = max(res, v + 1);
            for (auto x : mp)
            {
                res = max(x.second + 1, res);
            }
        }
        return res;
    }
};