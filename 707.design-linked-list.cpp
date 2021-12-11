/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList
{
    //* implement a singly linked list with
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

    //* destructor
    ~MyLinkedList()
    {
        Node *node = head;
        while (node)
        {
            Node *cur = node;
            node = node->next;
            delete cur;
        }
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        auto node = head;
        while (index--)
            node = node->next;
        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        head = new Node(val, head);
        if (size++ == 0)
            tail = head;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        auto node = new Node(val);
        if (size++ == 0)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        if (index == 0)
            return addAtHead(val);
        if (index == size)
            return addAtTail(val);
        Node dummy(0, head);
        Node *prev = &dummy;
        while (index--)
            prev = prev->next;
        prev->next = new Node(val, prev->next);
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        // use a dummy head in the stack
        Node dummy(0, head);
        Node *prev = &dummy;

        //itr to the node before the index node
        for (int i = 0; i < index; ++i)
            prev = prev->next;

        //tempt
        Node *node_to_delete = prev->next;
        prev->next = prev->next->next;

        // maintian the head the tail
        if (index == 0)
            head = prev->next;
        if (index == size - 1)
            tail = prev;
        delete node_to_delete;
        --size;
    }

private:
    struct Node
    {
        int val;
        Node *next;
        Node() : val{0}, next{nullptr} {}
        Node(int val_) : Node(val_, nullptr) {}
        Node(int val_, Node *next_) : val(val_), next(next_) {}
    }; // Node class

    Node *head;
    Node *tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
