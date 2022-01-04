# 997. Find the Town Judge

### 做法一(hashmap)

- 使用两个 ```hashmap```（array）cnt1 和 cnt2.
    - cnt1 记录谁trust i
    - cnt2 记录 i trust 谁

```cpp
        vector<int> cnt1(n + 1, 0); // {people who trust i}
        vector<int> cnt2(n + 1, 0); // {i trust who} 
```

- 找到那个 i：
    - cnt1 中 cn1[i] == n-1
    - cnt2 中 cnt[i] == 0

```cpp
        for (int i = 0; i < cnt1.size(); ++i)
        {
            if (cnt1[i] == n - 1 && cnt2[i] == 0)
                return i;
        }
```

- time
O(N+T), N is number of people, T is number of trust relations
- space
O(N)

<br/><br>

### 做法二(directed graph)

- 把trust想成一个 ```directed graph```
- ```一个点是 Judge iff 他的 indegree - outdegree == n-1```
- cnt 记录 undegree - outdegree of i node
    - t[0] 是 outdegree， 所以 count--
    - t[1] 是 indegree， 所以 count++
```cpp
        vector<int> cnt(n + 1, 0); // indegree - outdegree of i
        for (int i = 0; i < trust.size(); ++i)
        {
            cnt[trust[i][0]]--;
            cnt[trust[i][1]]++;
        }
```
