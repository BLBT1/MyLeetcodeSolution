
// union find with some constraints
// for all the edges that are under limit, we can make a union_find,
//  than check if p, q is connected (check if they have the same father)
// this would be O(EQ), E - number of edges, Q - number of queries


// Optimized: when we do union_find for a high limit graph, 
//            we could reuse graphs that composed from the small limit queries
// This would make sure each edge would be processed only once.
// Q(E*ElogE) -> ElogE for sorting the edges


```c++
class Solution {
    int father[100005];
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); ++i){
            queries[i].push_back(i);
        }

        for (int i = 0; i < n; ++i)
            father[i] = i;

        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);

        vector<bool> res(queries.size(), 0);
    
        int i = 0; 
        for(auto q: queries) {
            // because sorted already, i stand for the edges we can use that is smaller than limit
            int limit = q[2];
            while(i < edgeList.size() && edgeList[i][2] < limit){
                if(findFather(edgeList[i][0]) != findFather(edgeList[i][1])){
                    Union(edgeList[i][0], edgeList[i][1]);
                }
                ++i;
            }

            // finished union_find,  check if q, p is connection
            res[q[3]] = (findFather(q[0]) == findFather(q[1]));
        }

        return res;
    }


    int findFather(int i){
        if (i == father[i])
            return i;
        
        return findFather(father[i]);
    }

    void Union(int i, int j){
        int root_i = findFather(i), root_j = findFather(j);
        father[root_i] = root_j;
    }
};


// union find with some constraints
// for all the edges that are under limit, we can make a union_find,
//  than check if p, q is connected (check if they have the same father)
// this would be O(EQ), E - number of edges, Q - number of queries


// Optimized: when we do union_find for a high limit graph, 
//            we could reuse graphs that composed from the small limit queries
// This would make sure each edge would be processed only once.
// Q(E*ElogE) -> ElogE for sorting the edges

```
