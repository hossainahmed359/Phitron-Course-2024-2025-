// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges/search-12
// Search

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

int get_index_val(Node *head, long int x) {

    int index = 0;

    for (Node *i = head; i != NULL; i = i->next, index++)
    {
        if(i->val == x) return index;
    }
    

    return -1;
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

    int tst;
    cin >> tst;
    while (tst--)
    {
        Node *head = NULL;
        Node *tail = NULL;

        long int val;
        while (true)
        {
            cin >> val;
            if (val == -1)
            {
                break;
            }

            insert_at_tail(head, tail, val);
        }

        long int x; /* Target */
        cin >> x;

        int found_index_val = get_index_val(head, x);
        cout << found_index_val << endl;
    }

    return 0;
}