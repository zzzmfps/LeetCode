// 40ms, 97.55%; 19.6MB, 33.33%
class MyLinkedList
{
private:
    struct LinkedNode {
        int val;
        LinkedNode *prev, *next;
        LinkedNode(int v) : val(v), prev(nullptr), next(nullptr) {}
    };
    LinkedNode *head, *tail;
    int length = 0;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new LinkedNode(-1);
        tail = new LinkedNode(-1);
        head->next = tail, tail->prev = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        auto node = get_node_pointer(index);
        return (node ? node->val : -1);
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be
     * the first node of the linked list. */
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        addAtIndex(length, val);
    }

    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        auto shifted = (index == length ? tail : get_node_pointer(index));
        if (!shifted) return;
        auto previous = shifted->prev;
        auto new_node = new LinkedNode(val);
        previous->next = new_node, new_node->prev = previous;
        shifted->prev = new_node, new_node->next = shifted;
        length += 1;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        auto deleted = get_node_pointer(index);
        if (!deleted) return;
        auto _prev = deleted->prev, _next = deleted->next;
        _prev->next = _next, _next->prev = _prev;
        length -= 1;
    }

private:
    LinkedNode *get_node_pointer(int index)
    {
        LinkedNode *node = nullptr;
        if (index < 0 || index >= length) return node;
        if ((index << 1) < length) { // near head
            node = head->next;
            for (int i = 0; i < index; ++i) node = node->next;
        } else {
            node = tail;
            for (int i = index; i < length; ++i) node = node->prev;
        }
        return node;
    }
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
