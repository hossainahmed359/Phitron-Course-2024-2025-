// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges/browser-history-1
// Browser History

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *prev = NULL;
    Node *next = NULL;

    Node(string val)
    {
        this->val = val;
    }
};

void insert_at_head(Node *&head, Node *&tail, string val)
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

void insert_at_index(Node *&head, int index, string val)
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

void insert_at_tail(Node *&head, Node *&tail, string val)
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

void print_not_available()
{
    cout << "Not Available" << endl;
}

void go_to_prev_next_address(Node *&head, Node *&cursor, string address)
{
    if (address == "prev" && cursor->prev != NULL)
    {
        cursor = cursor->prev;
        cout << cursor->val << endl;
        return;
    }

    if (address == "next" && cursor->next != NULL)
    {
        cursor = cursor->next;
        cout << cursor->val << endl;
        return;
    }

    print_not_available();
}

void go_to_address(Node *&head, Node *&cursor, string address)
{

    stringstream ss(address);
    string word, word2;
    ss >> word >> word2;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->val == word2)
        {
            cout << curr->val << endl;
            cursor = curr;
            return;
        }
        curr = curr->next;
    }

    print_not_available();
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        string val;
        cin >> val;
        if (val == "end")
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    Node *cursor = head;

    int q;
    cin >> q;
    cin.ignore();
    while (q--)
    {

        string keyword;
        getline(cin, keyword);

        if (keyword == "prev" || keyword == "next")
        {
            go_to_prev_next_address(head, cursor, keyword);
        }
        else
        {
            go_to_address(head, cursor, keyword);
        }
    }

    // print_forward(head);

    return 0;
}
