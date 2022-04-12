# 19. Remove Nth Node From End of List

- 假设linked list的长度是 len（包括dummyNode）， 那从 dummyNode出发，我们需要走 len-n的长度到达 n node from end

- 为了删去他，我们其实是像到达 n node from end 的前一个 node

- 可以用一个cnt，p1每走一步cnt+1， cnt到 n-1 之后，p2再开始走，这样 p1 到nullptr了 p2停留的位置就是 n-1 from end

- lc1721 也用到了这个题目的思想
