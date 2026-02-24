### 1. path of string that can be *re-arranged* to become a palindrome
- because it is re-arranged, so it is not necessary to be a a real palindrome to become a result
- valid res "aabb" "aac" --> rule is there can only have one char to have odd count
                         --> we can use 26bits to represent all lower-case letters count odd/event
                         --> '0000010111' - 0 means this char has even count
                                          - 1 means this char has odd count
                                          - a valid res should only has one 1 from the bits representation


### 2. 通常在树里数path - how to traverse all the paths from a tree in O(N) - 但是这个题不能用这个套路
- each path in a tree can only has one turnaround(拐点) point. 我们可以遍历所有的拐点in O（N）
- 对于每个path，就是遍历拐点的左链和右链 来找到多少个edge上的char counts


### 3. 这个题目中 我们可以想 
- 对于所有的 （u，v）的 char count 其实是 （u，r）的 char count + （v，r） 的char count。 r是 tree root
- （u,v）char count = (u, r) char count + (v,r) char count - 2* (common ancestor path)
    -> because the redundant part is 2*X, so this would not affect the odd/event of (u,v) char count
- 所以我们可以通过 dfs 找出所有 node x 的 （x，r） 的 char count -> unordered_map <int, int> count // char count bits -> count


```c++
class Solution {
    unordered_map<int, int> count; // bit char count state -> count (ex, "ac" appeared *2 from the example#1)
    long long res = 0;
    unordered_map<int, vector<pair<int, char>>> adj;
    // string s;
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        // this->s = s;
        // build the graph
        // starting from 1, because root is at 0
        for(int i = 1; i < parent.size(); ++i){
            int p = parent[i];
            adj[p].push_back({i, s[i]});
        }

        int bitCount = 0;
        
        dfs(0, -1, bitCount);
        return res;
    }

    void dfs(int curr, int parent, int bitCount){
        // if we see the other bitCount is the same, like '01' -> '01' than it is valid
        if (count.find(bitCount) != count.end()){
            res += count[bitCount];
        }

        // find all the other bitCount Y, such that (Y+ curr bitCount) can be valid (only a single 1)
        //     10100
        // XOR 10101 ==> 00001  (a xor b = c)
        //  know a xor b = c, can we say a xor c = b
        // so we can use xor for adding odd and even ==> odd+odd = even, even+even=even, even+odd = od
        for (int i = 0; i < 26; ++i) {
            int y = bitCount ^ (1 << i);
            if (count.find(y) != count.end()){
                res += count[y];
            }
        }

        count[bitCount] += 1;

        // find next to finish dfs
        for(auto nxt: adj[curr]){
            if (nxt.first == parent) 
                continue;
            char ch = nxt.second;
            int nxtBitCount = bitCount ^ (1<<(ch-'a'));
            dfs(nxt.first, curr, nxtBitCount);
        }
    }   
};

// dfs --> 
// for all possible 2 nodes, check if is a palindrome
// 

// abcd ==> is palindrome
```
