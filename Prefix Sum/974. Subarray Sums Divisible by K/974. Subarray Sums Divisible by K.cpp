class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> Map;

        Map[0] = 1;
        int presum = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            presum += A[i];
            // to avoid presum goes to negative
            int r = presum > 0 ? presum % K : (presum % K + K) % K;
            res += Map[r];
            Map[r]++;
        }
        return res;
    }
};