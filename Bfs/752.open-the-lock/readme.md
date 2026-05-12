
// "0000"

// --> each time we can pick a digit of of 4, either +1 or -1
//     +1 -- 0->1 ... 9->0
//     -1 -- 9->8 ... 0->9 

// each round, we can have 8 operations, 4 pos to +/- 1

```c++
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set d_set(deadends.begin(), deadends.end());
       
        queue<string> q;
        unordered_set<string> visited;

        if(d_set.find("0000") != d_set.end())
            return -1;

        q.push("0000");
        visited.insert("0000");

        int count = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                string curr = q.front();
                q.pop();

                if(curr == target) return count;

                // find all all of the nexts
                // +1 
                for(int pos = 0; pos < 4; ++pos){
                    string nxt = curr;
                    nxt[pos] +=1;
                    if(nxt[pos]-'0' == 10){
                        nxt[pos] = '0';
                    }

                    if(d_set.find(nxt) != d_set.end())
                        continue;

                    if (visited.find(nxt) != visited.end())
                        continue;
                    
                    visited.insert(nxt);
                    q.push(nxt);
                }

                // -1
               for(int pos = 0; pos < 4; ++pos){
                    string nxt = curr;
                    nxt[pos] -=1;
                    if(nxt[pos]-'0' == -1){
                        nxt[pos] = '9';
                    }

                    if(d_set.find(nxt) != d_set.end())
                        continue;

                    if (visited.find(nxt) != visited.end())
                        continue;
                    
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
            count += 1;
        }

        return -1;
    }
};


// "0000"

// --> each time we can pick a digit of of 4, either +1 or -1
//     +1 -- 0->1 ... 9->0
//     -1 -- 9->8 ... 0->9 

// each round, we can have 8 operations, 4 pos to +/- 1

```