/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        //* this problem is a dfs problem
        //* solve by recusion
        dfs(head);
        return head;
    }
    //* this is a helper method to handle treversal recusively
    Node *dfs(Node *head)
    {
        if (!head)
            return head;
        // record the child node and the next node
        // the ptr to them will be cut
        Node *child = head->child;
        Node *next = head->next;
        head->child = nullptr;

        if (next && child)
        {

            // recursively find the end of the child and the next
            Node *nextEnd = dfs(next);
            Node *childEnd = dfs(child);

            head->next = child;
            child->prev = head;

            childEnd->next = next;
            next->prev = childEnd;

            return nextEnd;
        }
        else if (next && !child)
        {
            // just handle the next node
            Node *nextEnd = dfs(next);
            return nextEnd;
        }
        else if (!next && child)
        {
            Node *childEnd = dfs(child);

            head->next = child;
            child->prev = head;

            return childEnd;
        }
        else
        { // no child no next
            return head;
        } // end if
    }
};
// @lc code=end
