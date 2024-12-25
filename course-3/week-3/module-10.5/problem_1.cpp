// Question: Take two doubly linked lists as input and check if they are the same or not.

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

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void compare_list(Node *head_one, Node *head_two)
{
    bool flag = true;

    Node *i = head_one, *j = head_two;

    while (i != NULL && j != NULL)
    {

        if (i->val != j->val)
        {
            flag = false;
            break;
        }

        i = i->next;
        j = j->next;
    }

    if (i != NULL || j != NULL)
    {
        flag = false;
    }

    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{

    Node *head_one = NULL;
    Node *tail_one = NULL;

    while (true)
    {
        int val;
        cin >> val;

        if (val == -1)
        {
            break;
        }

        insert_at_tail(head_one, tail_one, val);
    }

    Node *head_two = NULL;
    Node *tail_two = NULL;

    while (true)
    {
        int val;
        cin >> val;

        if (val == -1)
        {
            break;
        }

        insert_at_tail(head_two, tail_two, val);
    }

    compare_list(head_one, head_two);

    return 0;
}