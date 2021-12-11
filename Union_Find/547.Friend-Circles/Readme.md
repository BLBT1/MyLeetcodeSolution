# 547.Friend-Circles
这个题是经典的union find 模板题，一定要牢记于心！

这题的本质的是找图里有几个连通分量 (number of ```connected components``` in the graph)

1.首先定义一个hashmap，key是图中每个node，val就是这个元素的老祖宗（此比喻很经典，出自guan神), 且初始每个人都是自己的老祖宗
```cpp
        unordered_map<int, int> father;
        for(int i = 0; i < n; ++i)
            father[i] = i;
```


2. adj matrix 中每个相连关系， 如果两个人有不同的老祖宗，但是又在matrix里相连，则由他们两个建立关系（union在一起）

    - findFather -> find()

    - union2Grps -> union()
    
    - 顾名思义 union-find



```cpp
        for(int i  = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if (i != j && isConnected[i][j])
                    if(findFather(i) != findFather(j))
                        union2Grps(i, j);
            }
```

3. 当所有相连关系走完，则需用set去重，每个人都找自己的老祖宗，且把自己祖宗加进set, 最后set里有几个祖宗，整个图就有几个连通分量

```cpp
        unordered_set<int> ancestors;
        for (int i = 0; i < n; ++i)
        {
            father[i] = findFather(i);
            ancestors.insert(father[i]);
        }
        return ancestors.size();
```

4.接下来是核心， 我们需要定义union和find这两个function

- findFather(): 如果我不是我自己的老祖宗，那我的老祖宗是谁？是我爸的老祖宗!! 那我爸的老祖宗是谁？ 让他问我爷爷去！！！

```cpp
        //* find the ancestor of x + path compression
    int findFather(int x)
    {
        if (father[x] == x)
            return father[x];

        // 如果我自己不是我自己的祖先
        // 我爸爸祖先就是我的祖先
        // * path compression
        father[x] = findFather(father[x]);
        return father[x];
    }
```

- union(): 各自找到自己的老祖宗，然后辈分小的老祖宗认辈分大的老祖宗为老祖宗


```cpp
    void union2Grps(int i, int j)
    {
        i = findFather(i);
        j = findFather(j);
        if (i <= j)
            father[j] = i;
        else
            father[i] = j;
    }
```


[Leetcode Link](https://leetcode.com/problems/number-of-provinces/)