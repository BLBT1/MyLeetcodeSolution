/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        // each node has their parent ptr
        // think as finding the intersection of two linked list
        Node *ptr1 = p;
        Node *ptr2 = q;
        while (ptr1 != ptr2)
        {
            if (ptr1 != nullptr)
                ptr1 = ptr1->parent;
            else
                ptr1 = q;

            if (ptr2 != nullptr)
                ptr2 = ptr2->parent;
            else
                ptr2 = p;
        }
        return ptr1;
    }
};