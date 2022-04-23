/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
    Node *prev = nullptr;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        inorder(root);
        tail->right = head;
        head->left = tail;

        return head;
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev == nullptr)
        {
            prev = root;
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        tail = root;

        inorder(root->right);
    }
};