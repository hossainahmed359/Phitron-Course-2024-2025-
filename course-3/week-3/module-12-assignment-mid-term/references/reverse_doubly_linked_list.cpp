#include <bits/stdc++.h>
using namespace std;

// INSERTION
class Node
{
public:
    int val;
    Node *prev = NULL;
    Node *next = NULL;

    Node(int val)
    {
        this->val = val;
    }
};

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

// Reverse Doubly Linked List
void reverse_doubly_linked_list(Node *head, Node *tail)
{
    Node *left = head;
    Node *right = tail;

    while (left != right && left->prev != right)
    {
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;

        left = left->next;
        right = right->prev;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;

        if (val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
    }

    reverse_doubly_linked_list(head, tail);

    print_forward(head);

    return 0;
}