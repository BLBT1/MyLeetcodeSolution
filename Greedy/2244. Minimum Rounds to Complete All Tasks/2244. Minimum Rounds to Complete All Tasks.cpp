class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        int n = tasks.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; ++i)
        {
            cnt[tasks[i]]++;
        }
        
        int round = 0;
        // 能做3就3， 如果还剩下，就 +1（做2）
        for(auto p: cnt)
        {
            if(p.second == 1)
                return -1;
            int sum = 0;
            sum = p.second/3;
            if(p.second - 3*sum > 0)
                sum += 1;
            round += sum;
        }
        return round;
    }
};

// 9 -> 3*3
// 7
    
// 3 -> 1
// 4 -> 2+2
// 5 -> 2+3
// 6 -> 2