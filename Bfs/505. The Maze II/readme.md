# 505. The Maze II

- You actually can revisited a location, as long as your current travaled distance is smaller than the previous visit. 所以要出栈的时候才设为 visited

- when use vector as the element in priority queue and std::greater as comparator, the lexicographical order will be used for comparison
```c++
    using pos = vector<int>;
    priority_queue<pos, vector<pos>, greater<>> pq;
```

the first int in vector would be used to compare, then the second int, etc.
so the distance between 2 position should be used as the first element

- greater will be min heap, by default, less<> is for max heap
- heap insertion and deleteion are O(logN) and pop is O(1)
- store the dist is the total dist from the start point

- this is key for this problem, we mark visited on pop, not on push, because it is possible to revisit a point if from different path.
  only on pop, the shortest distance has been finalized  
