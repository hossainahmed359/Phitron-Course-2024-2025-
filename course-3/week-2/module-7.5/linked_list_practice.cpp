#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;

    Node(int val)
    {
        this->val = val;
    }
};

void insert_node_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insert_node_at_tail(Node *&head, Node *&tail, int val)
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
};

void insert_node_at_index(Node *&head, int index, int val)
{

    Node *newnode = new Node(val);

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_node_at_head(Node *&head)
{
    Node *tmp = head;
    head = tmp->next;
    delete tmp;
}

void delete_node_at_index(Node *&head, int index)
{

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deletenode = tmp->next;
    tmp->next = deletenode->next;
    delete deletenode;
}

void sort_linked_list(Node *&head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if(i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}

void print_linked_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

void print_linked_list_reverse(Node *tmp)
{
    if (tmp == NULL)
    {
        return;
    }

    print_linked_list_reverse(tmp->next);
    cout << tmp->val << " ";
}

int main()
{

    int val;

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cin >> val;

        if (val == -1)
        {
            break;
        }

        insert_node_at_tail(head, tail, val);
    }

    print_linked_list(head);
    cout << endl;

    sort_linked_list(head);

    print_linked_list(head);

    return 0;
}