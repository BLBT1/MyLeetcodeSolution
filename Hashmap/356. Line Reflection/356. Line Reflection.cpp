class Solution {
public:
    bool isReflected(vector<vector<int>>& pts) 
    {
        unordered_set<string> st;
        int left = INT_MAX, right = INT_MIN; 
        for(auto p: pts)
        {
            st.insert(to_string(p[0])+","+to_string(p[1]));
            left = min(left, p[0]);
            right = max(right, p[0]);
        }
        
        int sum = right + left;
        for(auto p: pts)
        {
            if(st.find(to_string(sum-p[0])+","+to_string(p[1])) == st.end())
                return false;
        }
        
        return true;
    }
};