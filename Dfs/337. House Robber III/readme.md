# 337. House Robber III

这题看起来和house rober 1，2 一脉相承，只不过是数据结构改成了二叉树， 但是明显dp对此题不再适用。此题应该使用 ```dfs + memo``` 来解决

### 解题思路
首先需要发现的是， 如果我们正在处理的 node 取了，则接下来他的两个left child 和 right child 都不能取。所以总共有2种状态，我们可以分别定义为0，1。

- 0 <- 此点的val不可选
- 1 <- 此点的val可选可不选 
```cpp
        // 0 <- cannot choose
        // 1 <- can choose
```
定义一个变量 state 在dfs 中 pass down 下一个点的状态。
```cpp
    int dfs(TreeNode *root, int state){...}
```

接着， dfs中如果当天点状态为 0， 则他的left child 和 right child 都可以选择， 状态pass 为 1。而此点可得到的最大利润看就是和左孩子和右孩子最大利润之和

```cpp
        if (state == 0)
        {
            res = dfs(root->left, 1) + dfs(root->right, 1);
        }
```
如果当前的状态为 1， 则需要分别考虑 选 和 不选 当前点的值， 取大的利润为当前点的最大利润

```cpp
        int take = root->val + dfs(root->left, 0) + dfs(root->right, 0);
        int notTake = dfs(root->left, 1) + dfs(root->right, 1);
        res = max(take, notTake);
```
到此位置 dfs 的部分就结束了，但是我们可以发现这样的答案是跑不完所以的test case的， 还有明显的优化空间。 因为递归的原因， 很多点的最大值被重复计算了，所以可以用memo 的思维来记录。用两个```hashmap```分别记录每个点在状态 0 和状态 1 下的最大值
```cpp
        unordered_map<TreeNode *, int> state0; // the largest for state0 at the node
        unordered_map<TreeNode *, int> state1; // the largest for state1 at the node 
```