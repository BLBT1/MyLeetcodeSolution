class Solution {
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {    
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        // this problem is the same as finding the max number of non-overlapping intervals
        // 因为至少要保证每个non-overlapping的interval 都有一根arrow穿过， 剩下overlapping 的可以顺便穿过
        sort(points.begin(), points.end(), cmp);
        const int n = points.size();
        int i = 0;
        int cnt = 0;
        while(i < n)
        {
            cnt++;
            int j = i+1;
            while(j < n && points[j][0] <= points[i][1])
                j++;
            i = j;
        }
        
        return cnt;
    }
};