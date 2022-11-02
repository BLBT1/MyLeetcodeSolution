class Solution {
public:   
    bool canMutate(string &str1, string& str2)
    {
        // require str1 and str2 both has 8 chars
        int cnt = 0;
        for(int i = 0; i < str1.size(); ++i)
        {
            if(str1[i] != str2[i])
                cnt++;
        }
        return cnt == 1;
    }
    
    int minMutation(string start, 
                    string end, 
                    vector<string>& bank) 
    {    
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> bankset(bank.begin(), bank.end());
        
        if(start != end && bankset.find(end) == bankset.end())
            return -1;
        int res = 0;
        q.push(start);
        while(!q.empty())
        {
            int len = q.size();
            for(int k = 0; k < len; ++k)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr == end)
                    return res;
                
                for(auto b: bankset)
                {
                    if(visited.find(b) == visited.end() && canMutate(curr, b))
                    {
                        q.push(b);
                        visited.insert(b);
                    }
                }
            }
            res += 1;
        }
        return -1;
    }
};