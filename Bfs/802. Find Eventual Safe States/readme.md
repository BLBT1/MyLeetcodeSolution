# 802. Find Eventual Safe States

- safe node 要保证所有的path都指向terminal node， 所以要同拓扑排序

- 反向思维，从出度为0 的点开始往中间走，将这些点剪除之后，接下来出度为0的节点，肯定还是safe的节点。以此BFS不断推进，如果还有剩下的节点，那么他们肯定出度都不为0，即是互相成环的，可以终止程序。
