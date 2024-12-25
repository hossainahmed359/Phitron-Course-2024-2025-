// Question: Take a doubly linked list as input and reverse it. After that print the linked list.

#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List
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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;

    tail = newnode;
}

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void reverse_list(Node *head, Node *tail) {

    for (Node *i = head , *j = tail; i != j && i->prev != j; i = i->next , j = j->prev)
    {
        swap(i->val, j->val);
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

    reverse_list(head, tail);

    print_forward(head);

    return 0;
}