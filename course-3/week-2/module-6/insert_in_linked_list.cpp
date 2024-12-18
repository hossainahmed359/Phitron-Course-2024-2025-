#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Insert At Head
void insert_at_head(Node *(&head), int val)
{
    // cout << "insert_at_head: " << head << endl;

    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

// Insert At Tail
void insert_at_tail(Node *(&head), int val)
{
    // cout << "insert_at_tail: " << head << endl;

    Node *newnode = new Node(val);

    // Handling Edge Case if head is null
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;
}

// Insert At Tail OPTIMIZED
void insert_at_tail_opt(Node *(&head), Node *(&tail), int val)
{
    // cout << "insert_at_tail_opt: " << head << endl;

    Node *newnode = new Node(val);

    // Handling Edge Case if head is null
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    // tail = newnode;
    tail = tail->next;
}

// Insert At Any Position
void insert_at_any_pos(Node *(&head), int index, int val)
{
    // cout << "insert_at_any_pos: " << head << endl;

    Node *newnode = new Node(val);

    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;

    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main()
{

    // Node *head = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *tail = new Node(40);

    // head->next = a;
    // a->next = b;
    // b->next = tail;

    // insert_at_head(head, 100);

    // insert_at_any_pos(head, 3, 430);

    // insert_at_tail(head, 130);

    // insert_at_tail_opt(head, tail, 111);

    // print_linked_list(head);

    // Input
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        insert_at_tail_opt(head, tail, val);
    }

    print_linked_list(head);

    return 0;
}
