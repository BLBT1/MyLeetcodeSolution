// 1. build the tree from the array (with adjcency list)
// 2. for each tree, use dfs to find the subtree size, remaininig for graph is total size(n) - both subtree, highest score is all 3 parts times together
// 3. dfs to record the max result

```c++
class Solution {
    int n;
    long highestScore;
    int cnt;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();

        int root = -1;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] == -1){
                root = i;
                continue;
            }
            adj[parents[i]].push_back(i);
        }
        
        dfs(adj, root);
        return cnt;
    }

    long dfs(unordered_map<int, vector<int>> &adj, int curr) {
        if(adj[curr].empty()){
            if (n-1 == highestScore) {
                cnt ++;
            } else if(n-1 > highestScore) {
                highestScore = n-1;
                cnt = 1;
            }
            return 1;
        }

        long currRes = 1;
        int subTreeSizeSum = 0;
        for(auto next: adj[curr]){
            int subTreeSize = dfs(adj, next);
            currRes = currRes * subTreeSize;
            subTreeSizeSum += subTreeSize;
        }
        currRes = currRes*(max(n-subTreeSizeSum-1,1));
        if (currRes > highestScore) {
            highestScore = currRes;
            cnt = 1;
        } else if (currRes == highestScore){
            cnt ++;
        }
        
        return subTreeSizeSum+1;
    }
};

// 1. build the tree from the array (with adjcency list)
// 2. for each tree, use dfs to find the subtree size, remaininig for graph is total size(n) - both subtree
// 3. dfs to record the max result

```

