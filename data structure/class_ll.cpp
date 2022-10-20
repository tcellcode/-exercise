#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node
{
private:
    int val = 0;
    Node *next = NULL;
    friend class LinkedList;
};

class LinkedList
{
private:
    int ll_len = 0;
    Node *head = NULL;

    void initHead(int n)
    {
        head = new Node();
        head->val = n;
    }

public:
    void print()
    {
        cout << "{";
        if (head == NULL)
        {
            cout << "<empty-ll>" << endl;
            return;
        }
        Node *curr_node = head;
        while (curr_node != NULL)
        {
            cout << curr_node->val << ", ";
            curr_node = curr_node->next;
        }
        cout << "\b\b}"
             << "\n<len " << ll_len << ">";
    }

    void pushFront(int n)
    {
        ++ll_len;

        if (head == NULL)
        {
            initHead(n);
            return;
        }

        Node *newNode = new Node();
        newNode->val = n;
        newNode->next = head;
        head = newNode;
    }

    void pushEnd(int n)
    {
        ++ll_len;

        if (head == NULL)
        {
            initHead(n);
            return;
        }

        Node *newNode = new Node();
        newNode->val = n;

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        tail->next = newNode;
    }

    void pushAt(int n, unsigned int idx)
    {
        ++ll_len;

        if (head == NULL)
        {
            initHead(n);
            return;
        }

        if (idx == 0)
        {
            pushFront(n);
            return;
        }

        Node *newNode = new Node();
        newNode->val = n;

        Node *curr_node = head;
        for (int i = 0; i < idx - 1; i++)
        {
            if (curr_node->next == NULL)
            {
                curr_node->next = newNode;
                return;
            }
            curr_node = curr_node->next;
        }

        newNode->next = curr_node->next;
        curr_node->next = newNode;
    }

    int access(unsigned int idx)
    {
        Node *curr_node = head;

        for (int i = 0; i < idx; i++)
        {
            if (curr_node == NULL or curr_node->next == NULL)
            {
                return 0;
            }
            curr_node = curr_node->next;
        }
        return curr_node->val;
    }

    void delNode(unsigned int idx)
    {
        --ll_len;

        Node *curr_node = head;

        if (idx == 0)
        {
            head = head->next;
            delete curr_node;
            curr_node = NULL;
            return;
        }

        for (int i = 0; i < idx - 1; i++)
        {
            if (curr_node->next == NULL)
            {
                return;
            }
            curr_node = curr_node->next;
        }

        delete curr_node->next;
        curr_node->next = NULL;
    }

    void delALl()
    {
        ll_len = 0;

        while (head != NULL)
        {
            delNode(0);
        }
    }
};

int main()
{
    LinkedList ll;
    for (int i = 0; i < 10; i++)
    {
        ll.pushEnd(i);
    }
    ll.print();
    cout << endl;
    cout << ll.access(-1);

    return 0;
}