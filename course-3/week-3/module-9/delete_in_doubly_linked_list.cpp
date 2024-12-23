#include <bits/stdc++.h>
using namespace std;

// DELETION
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

void delete_at_head(Node *&head, Node *&tail)
{
    Node *deletenode = head;
    head = head->next;
    delete deletenode;

    if (head == NULL)
    {
        tail = NULL;
        return;
    }

    head->prev = NULL;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    Node *deletenode = tail;
    tail = tail->prev;
    delete deletenode;

    if (tail == NULL)
    {
        head = NULL;
        return;
    }

    tail->next = NULL;
}

void delete_at_pos(Node *&head, int index)
{

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deletenode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;

    delete deletenode;
    
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

    delete_at_pos(head, 3);
    delete_at_pos(head, 3);

    print_forward(head);

    return 0;
}