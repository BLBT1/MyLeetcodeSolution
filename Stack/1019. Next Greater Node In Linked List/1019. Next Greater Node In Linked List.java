/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private int len = 0;

    public int[] nextLargerNodes(ListNode head)
    {
        // first reverse the linked list
        ListNode reversed = reverseList(head);
        int[] res = new int[len];
        Stack<Integer> stack = new Stack<>();
        for(int i = len-1; reversed != null; reversed = reversed.next, --i)
        {
            while(!stack.isEmpty() && stack.peek() <= reversed.val)
            {
                stack.pop();
            }
            if(stack.isEmpty())
                res[i] = 0;
            else
                res[i] = stack.peek();
            stack.push(reversed.val);
        }
        return res;
    }

    ListNode reverseList(ListNode head)
    {
        ListNode prev = null;
        ListNode curr = head;
        ListNode temp = null;
        while(head != null)
        {
            len++;
            temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
}