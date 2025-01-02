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

// Insert At Tail OPTIMIZED
void insert_at_tail(Node *(&head), Node *(&tail), int val)
{
    // cout << "insert_at_tail: " << head << endl;

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

// Reverse Singly Linked List
void reverse_linked_list(Node *&head, Node *&tail, Node *tmp)
{

    if (tmp->next == NULL)
    {
        head = tmp;
        return;
    }

    reverse_linked_list(head, tail, tmp->next);

    tmp->next->next = tmp;
    tmp->next = NULL;
    tail = tmp;

    return;
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

int main()
{

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

        insert_at_tail(head, tail, val);
    }

    reverse_linked_list(head, tail, head);

    print_linked_list(head);

    return 0;
}
