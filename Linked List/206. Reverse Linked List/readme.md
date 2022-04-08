# 206. Reverse Linked List

很经典的问题，递归和非递归都要会写

- 核心是反转 head到prev后，仍然能记住next的位置

```cpp  

    1->2->3  => 1<-2->3
p   h           p  h

```
