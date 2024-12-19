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
void insert_at_tail_opt(Node *(&head), Node *(&tail), int val)
{
    // cout << "insert_at_tail_opt: " << head << endl;

    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = tail->next;
}

// Delete At Head
void delete_at_head(Node *(&head))
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
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
    
    delete_at_head(head);
    
    print_linked_list(head);

    return 0;
}