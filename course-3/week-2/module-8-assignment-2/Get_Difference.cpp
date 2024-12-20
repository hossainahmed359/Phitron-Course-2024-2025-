// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges/get-difference
// Get Difference

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

void print_minmax_diff(Node *head)
{
    int min = head->val;
    int max = head->val;
    for (Node *i = head->next; i != NULL; i = i->next)
    {
        if (i->val < min)
        {
            min = i->val;
        }
        else if (i->val > max)
        {
            max = i->val;
        }
    }

    cout << max - min << endl;
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

    print_minmax_diff(head);

    return 0;
}