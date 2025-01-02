// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges/queries-again-1
// Queries Again

#include <bits/stdc++.h>

using namespace std;

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

int get_len(Node *head)
{

    int len = 0;

    Node *curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    return len;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insert_at_index(Node *&head, int index, int val)
{
    Node *newNode = new Node(val);

    Node *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }

    newNode->next = curr->next;
    newNode->prev = curr;

    curr->next->prev = newNode;
    curr->next = newNode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void print_forward(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

void print_backward(Node *tail)
{
    Node *curr = tail;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->prev;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        int len = get_len(head);

        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x < len)
        {
            insert_at_index(head, x, v);
        }
        else if (x == len)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x > len)
        {
            cout << "Invalid" << endl;
            continue;
        }

        cout << "L -> ";
        print_forward(head);
        cout << endl;

        cout << "R -> ";
        print_backward(tail);
        cout << endl;
    }

    // insert_at_index(head, 3, 10);

    // print_forward(head);

    // cout << endl;

    // print_backward(tail);

    return 0;
}
