// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges/same-to-same-1
// Same to Same

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
    tail = newnode;
}

int is_same_to_same(Node *head_of_first, Node *head_of_second)
{
    Node *i = head_of_first, *j = head_of_second;
    while (i != NULL && j != NULL)
    {
        if (i->val != j->val)
        {
            return 0;
        }
        i = i->next, j = j->next;
    }

    if(i == NULL && j == NULL) return 1;

    return 0;
}

int main()
{

    // First Linked List
    Node *head_of_first = NULL;
    Node *tail_of_first = NULL;

    int val_of_first;
    while (true)
    {
        cin >> val_of_first;
        if (val_of_first == -1)
        {
            break;
        }

        insert_at_tail(head_of_first, tail_of_first, val_of_first);
    }

    // Second Linked List
    Node *head_of_second = NULL;
    Node *tail_of_second = NULL;

    int val_of_second;
    while (true)
    {
        cin >> val_of_second;
        if (val_of_second == -1)
        {
            break;
        }

        insert_at_tail(head_of_second, tail_of_second, val_of_second);
    }

    // Check if same to same
    if (is_same_to_same(head_of_first, head_of_second))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}