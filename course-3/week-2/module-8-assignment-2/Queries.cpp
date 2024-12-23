// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges/queries-6-1
// Queries

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long int val;
    Node *next = NULL;

    Node(long int val)
    {
        this->val = val;
    }
};

void insert_at_head(Node *&head, Node *&tail, long int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, long int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}

void delete_at_index(Node *&head, Node *&tail, long int index)
{

    if (head == NULL)
    {
        return;
    }

    if (index == 0)
    {
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete deleteNode;
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;

        if (tmp == NULL || tmp->next == NULL)
        {
            return;
        }
    }

    Node *deleteNode = tmp->next;
    tmp->next = deleteNode->next;

    if (deleteNode == tail)
    {
        tail = tmp;
    }

    delete deleteNode;
}

void delete_at_head(Node *&head, long int index)
{
    Node *deleteNode = head;
    head = deleteNode->next;
    delete deleteNode;
}

void delete_at_index_alt(Node *&head, long int index)
{

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail, long int index /* Always last index */)
{

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    delete deleteNode;
    tail = tmp;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int get_linked_list_len(Node *head)
{
    if (head == NULL)
        return 0;

    int len = 0;
    for (Node *i = head; i != NULL; i = i->next)
    {
        len++;
    }
    return len;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        long int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            // int len = get_linked_list_len(head);
            // if (v < len)
            // {
            //     delete_at_index(head, tail, v);
            // }

            int len = get_linked_list_len(head);
            if (v == 0)
            {
                delete_at_head(head, v);
            }
            else if (v < len - 1)
            {
                delete_at_index_alt(head, v);
            }
            else if (v == len - 1)
            {
                delete_at_tail(head, tail, v);
            }
        }

        print_linked_list(head);
        cout << endl;
    }

    return 0;
}
