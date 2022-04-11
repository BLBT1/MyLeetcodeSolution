# 160. Intersection of Two Linked Lists

- 假设链表A，B 有交点

- 假设 链表A到 交点的距离是a， B到交点的距离是b，交点到链表tail的距离是c。

- 那我们用双指针一个从headA开始走，一个从headB开始走，以同样速度走，当他们都走了 a+b+c的距离后，他们相遇的点就是交点
