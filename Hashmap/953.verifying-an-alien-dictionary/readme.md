```c++
class Solution {
    unordered_map<char, int> order_mp; // idx of order for char
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); ++i){
            order_mp[order[i]] = i;
        }

        for(int i = 0; i< words.size()-1; ++i){
            string w1 = words[i];
            string w2 = words[i+1];
            if(!isSorted(w1, w2)){
                return false;
            }
        }
        
        return true;
    }

    bool isSorted(string &w1, string &w2){
        int len = min(w1.size(), w2.size());
        for(int i = 0 ;i < len; ++i){
            if(w1[i] == w2[i]){
                continue;
            }

            if(order_mp[w1[i]] > order_mp[w2[i]])
                return false;
            else 
                return true;
        }

        return w1.size() <= w2.size();
    }
};
```