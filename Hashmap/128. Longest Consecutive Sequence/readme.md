# 128. Longest Consecutive Sequence

## Brute force: Sort

## Union Find

我们想把每个相连的chain都group在一起，然后找到最大的group。 遍历每个元素n，如果他的father[n]和 father[n+1] 或 father[n-1] 不在一个group， 我们就需要把他们union成一个group

### time

find: O(logN)

Union: O(logN)

Space: O(N)

## DFS starting from the smallest element in the chain

Time O(N)
Space O(N)
