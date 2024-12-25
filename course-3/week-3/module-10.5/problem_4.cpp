//  Question: You have a doubly linked list which is empty initially. You need to take a value Q which refers to queries. For each query you will be given X and V. You will insert the value V to the Xth index of the doubly linked list and print the list in both left to right and right to left. If the index is invalid then print “Invalid”.

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

int get_list_length(Node *head)
{
    int len = 0;
    for (Node *i = head; i != NULL; i = i->next)
    {
        len++;
    }
    return len;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;

    head = newnode;
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

    tail->next = newnode;
    newnode->prev = tail;

    tail = newnode;
}

void insert_at_pos(Node *&head, int index, int val)
{
    Node *newnode = new Node(val);

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    newnode->prev = tmp;
    newnode->next = tmp->next;

    tmp->next->prev = newnode;
    tmp->next = newnode;
}

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

void print_backward(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }

    cout << endl;
}

int main()
{

    int q;
    cin >> q;

    Node *head = NULL;
    Node *tail = NULL;

    while (q--)
    {

        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);

            print_forward(head);
            print_backward(tail);
        }
        else if (x < get_list_length(head))
        {

            insert_at_pos(head, x, v);

            print_forward(head);
            print_backward(tail);
        }
        else if (x == get_list_length(head))
        {

            insert_at_tail(head, tail, v);

            print_forward(head);
            print_backward(tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}