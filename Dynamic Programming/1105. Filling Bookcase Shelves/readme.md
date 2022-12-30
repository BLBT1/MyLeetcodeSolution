# 1105. Filling Bookcase Shelves

dp[i] => the min height for books[0: i]. we search for j which is the first book of the last level

每次初始要首先更新：

```cpp
            int maxHeight = books[i][1];  // the maxHegith of the last level
            int totalWidth = books[i][0]; // the total width of this level
            dp[i] = dp[i - 1] + maxHeight;
```

再搜索j：

```cpp
            for (int j = i - 1; j > 0; --j)
            {
                totalWidth += books[j][0];
                if (totalWidth > shelfWidth)
                    break;
                maxHeight = max(maxHeight, books[j][1]);
                dp[i] = min(dp[i], maxHeight + dp[j - 1]);
            }
```
