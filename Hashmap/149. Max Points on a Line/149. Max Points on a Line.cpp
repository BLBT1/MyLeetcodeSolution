class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int res = 1;
        for(auto p: points)
        {
            int v = 0;
            map<pair<int, int>, int> cnt; // pair<int, int> must use ordered map
            // each point has a map, we use the gcd()
            for(auto q: points)
            {
                if(p == q) continue;
                int dy = p[1] - q[1];
                int dx = p[0] - q[0];
                
                if(dx == 0) 
                    v += 1;
                
                int a = dy/gcd(dy, dx);
                int b = dx/gcd(dy, dx);
                cnt[make_pair(a, b)]++;
            }
            
            res = max(res, v);
            for(auto p: cnt)
                res = max(res, p.second+1);
        }
        return res;
    }
};


// map 里要确保每个斜率的表达方式都是unique的，
// 那用double的话， 精确度肯定有影响， 最好的办法是用dy/dx的最简分数来标识
// 那就是说 dy/gcd(dy, dx) , dx/gcd(dy, dx)