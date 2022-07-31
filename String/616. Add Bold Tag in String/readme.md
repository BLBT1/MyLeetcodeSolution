# 616. Add Bold Tag in String

1. 此题的难点其实是如何合并区间， 参考 lc 56，我们可以用扫描线的方法来做

2. 合并完区间后，需要继续合并相连的区间， 比如 [1,3], [4, 5] 要合并为 [1,5]， 可以用以下代码完成

```cpp
        // step2: merge interval (lc 56)        
        if(ivl.empty())
            return s;
        vector<pair<int, int>> merged;
        vector<pair<int, int>> temp;
        for(auto &p: ivl)
        {
            temp.push_back({p.first, 1});
            temp.push_back({p.second, -1});
        }
        sort(temp.begin(), temp.end(), cmp());
        int cnt = 0;
        int beg, end;
        for(auto &p: temp)
        {
            cnt += p.second;
            if(cnt == 1 && p.second == 1)
                beg = p.first;
            if(cnt == 0 && p.second == -1)
            {
                end = p.first;
                merged.push_back({beg, end});
            }
        }
        vector<pair<int, int>> connected;
        connected.push_back(merged.front());
        if(merged.size() > 1)
        {
            for(int i = 1; i < merged.size(); ++i)
            {
                if(merged[i].first == connected.back().second+1)
                    connected.back().second = merged[i].second;
                else
                    connected.push_back(merged[i]);
            }
        }
```
