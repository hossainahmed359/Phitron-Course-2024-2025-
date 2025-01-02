// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges/palindrome-26-2
// Palindrome

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

void check_is_palindrome(Node *head, Node *tail)
{
    Node *left = head;
    Node *right = tail;

    bool flag = true;

    while (left->prev != right && left != right)
    {
        if (left->val != right->val)
        {
            flag = false;
            break;
        }

        left = left->next;
        right = right->prev;
    }

    if (flag)
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

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    check_is_palindrome(head, tail);

    return 0;
}
