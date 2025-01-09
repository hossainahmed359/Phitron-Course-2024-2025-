// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges/same-or-not-4
// Same or Not II

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

// STACK IMPLEMENTATION
class Stack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        sz--;
        Node *tmp = tail;
        tail = tail->prev;

        if (tail == NULL)
        {
            head = NULL;
        }

        delete tmp;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

// QUEUE IMPLEMENTATION
class Queue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        sz--;
        Node *tmp = head;
        head = head->next;
        delete tmp;

        if (head == NULL)
        {
            tail = NULL;
            return;
        }

        head->prev = NULL;
    }

    int back()
    {
        return tail->val;
    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    // n -> stack , m -> queue

    Stack stA;
    Queue queB;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        stA.push(val);
    }

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        queB.push(val);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;

    while (!(stA.empty() && queB.empty()))
    {
        if (stA.top() != queB.front())
        {
            flag = false;
            break;
        }

        stA.pop();
        queB.pop();
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
