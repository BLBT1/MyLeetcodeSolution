class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        const int n = cost.size();
        int sum = 0;
        // 如果gas的总和 小于 cost的总和，那肯定不行
        for(int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
        }
        if(sum < 0)
            return -1;
        
        // 如果gas的总和 大于 cost的总和，那肯定有解。且题目告知我们只有一个解，
        // 所以那个解肯定是存在的，只需要 循环一边所有的点找到他就可以
        
        // A -> B 走不下去了，说明 在AB 线路上任意一点都走不到B，假设这点是c
        // A -> C -> B
        // 因为 A能走到C， 所以 A->C 个 gas  > A->C 的cost
        // 那 A->B 的 gas - A->B 的cost > C->B 的gas - C->B的cost
        // 我们下一个起点只能是 B+1 的位置开始找
        sum = 0;
        int curr = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += gas[i] - cost[i];
            if(sum < 0)
            {
                sum = 0;
                curr = i+1;
            }
        }
        
        return curr;
    }
};

