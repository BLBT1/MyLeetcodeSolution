class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        for (int i = 0; i < cost.size(); ++i)
            total += gas[i] - cost[i];
        if (total < 0)
            return -1;

        int leftover = 0;
        int res = 0;
        for (int i = 0; i < cost.size(); ++i)
        {
            leftover += gas[i] - cost[i];

            // assume C is the first pt that can not be reached from res
            // then we cannot finish in any pt in [res:C]
            if (leftover < 0)
            {
                res = i + 1;
                leftover = 0;
            }
        }

        return res;
    }
};