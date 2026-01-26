# 142. Linked List Cycle II

- 快慢指针判断是否有环

- 双指针，x 从 head 开始， y 从 相遇点开始， 同速走， 相遇点就是环的起始点

- 基本思想， 设 m 为 head 到 环开始点的距离， n 为环的总长， x 为相遇点到环的起始点， 有为起始点到相遇点。f 为快指针的行走距离，s 为慢指针的距离。

- f = 2 s

- m+y+nk = m+y, k 是快指针遇见慢指针前绕的环数

- y = n-x， 消除y， 得到 m = x + (k-1)*n

- 所以以上x，y指针的方法成立

- 核心思想就是

*** head到环的起点 + 环的起点到快慢指针的相遇的点P = 环长度的若干倍 ***

algorithm:
- 所以算发就是 第一次快慢指针同时走找到相遇点P
- 然后再慢指针 和头指针同时走 直到相遇

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        bool hasCycle = false;
        while(fast->next != nullptr && fast->next->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle) return nullptr;
        
        while(head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return head;
    }
};

```