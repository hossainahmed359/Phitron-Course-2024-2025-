// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges/remove-duplicate-9-1
// Remove Duplicate

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

void remove_duplicates(Node *&head, Node *&tail)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        int targetval = i->val;
        Node *prev_node = i;
        Node *current_node = i->next;

        while (current_node != NULL)
        {
            Node *next_node = (current_node == tail) ? NULL : current_node->next;

            if (targetval == current_node->val)
            {
                Node *deletenode = current_node;

                if (current_node == tail)
                {
                    tail = prev_node;
                }

                prev_node->next = next_node;
                delete deletenode;
                current_node = next_node;
            }
            else
            {
                prev_node = current_node;
                current_node = current_node->next;
            }
        }
    }
}

void remove_duplicates_alt(Node *&head, Node *&tail)
{
    for (Node *i = head; i->next != NULL; i = i->next)
    {

        int targetVal = i->val;

        Node *prev = i;

        while (prev->next != NULL)
        {

            Node *current = prev->next;

            if (targetVal == current->val)
            {
                Node *deletenode = current;

                if (current->next == NULL)
                {
                    prev->next = NULL;
                    tail = prev;
                }
                else
                {
                    prev->next = current->next;
                }

                delete deletenode;
            } 

            prev = prev->next;
        }
    }
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

    remove_duplicates(head, tail);
    // remove_duplicates_alt(head, tail);

    print_linked_list(head);
    cout << endl;

    return 0;
}