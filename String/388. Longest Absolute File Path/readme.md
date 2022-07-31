# 388. Longest Absolute File Path

- 最重要的是要意识到，'\t'的个数就代表当前的file 的层级

- 我们要做的其实是类似与dfs的操作，一直走到最里层,　如果遇到file，就更新一下当前最长的路径

- 所以我们发现，file 之前的层级中的对应的路径中的file, 一定是我们最后遇到的，　比如说，

```
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext

```

dir/subdir2/subsubdir2/file2.ext 中， file2.ext 之前的层级一定是他最近遇到的，

- subdir2 override了 subdir1
- subsubdir2 override 了 subsubdir1 (subsubdir1 overrried file1.ext already)
因此，　发现这个规律后，　我们只需要用一个 vector记录最近一次遇到的那个层级的file就可以了

- 还需注意：如果文件在 k level,　那路径中还要加上 k 个 "/"
