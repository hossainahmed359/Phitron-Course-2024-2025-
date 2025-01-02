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

void print_backward(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
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

    newnode->prev = tail;
    tail->next = newnode;
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


    insert_at_pos(head, 3, 987);

    print_forward(head);
    // cout << endl;
    // print_backward(tail);

    return 0;
}