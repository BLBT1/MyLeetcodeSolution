# 815. Bus Routes

- 这个题是要找做多少的bus， 而不是做多少的站，所以需要建立的map是 把每个站对应到他停的 bus, 用bfs搜索的是公交车线路

```c++
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int, vector<int>> adj; // what bus the current bus can connect to
        for(int i = 0; i < routes.size(); ++i){
            for(int b = 0; b < routes[i].size(); ++b){
                adj[routes[i][b]].push_back(i);
            }
        }

        queue<int> q; // for the buses, not the stops, as we want to know the # of buses
        unordered_set<int> visited;
        for(auto curr_bus: adj[source]){
            q.push(curr_bus);
            visited.insert(curr_bus);
        }
        
        int count = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                auto curr = q.front();
                q.pop();

                // check if current bus can has stop
                for(auto stop: routes[curr]){
                    if(stop == target)
                        return count;

                    // find all the stops from the curr bus it connected to another bus
                    for (int nxt_bus: adj[stop]){
                        if(visited.find(nxt_bus) != visited.end()) 
                            continue;
                    
                        q.push(nxt_bus);
                        visited.insert(nxt_bus);
                    }
                }
            }

            count += 1;
        }
        
        return -1;
    }
};


// // buses are connected if it has a stop that is the same
// // we need a reverted index
// // 

// [1,2,7],[3,6,7]

// 1 -> 0
// 2 -> 0
// 7 -> 0, 1
// 3 -> 1
// 6 -> 1

// // we don't care about how many bus stop we need to travel at total

//  least number of buses -> bfs

```
