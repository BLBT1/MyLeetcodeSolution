
```c++
class FirstUnique {
    queue<int> q; // for ordering
    unordered_map<int, int> counts; // should never erase in count as a number might be added back again
public:
    FirstUnique(vector<int>& nums) {
        for(auto n: nums){
            q.push(n);
            counts[n] += 1;
        }
    }
    
    int showFirstUnique() {
        // if we find any number in the front that is not unique, we don't need to consider in future
        // so just pop
        while(!q.empty() && counts[q.front()] > 1){
            q.pop();
        }
        if(q.empty()) return -1;
        return q.front();
    }
    
    void add(int value) {
        q.push(value);
        counts[value]+=1;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
```