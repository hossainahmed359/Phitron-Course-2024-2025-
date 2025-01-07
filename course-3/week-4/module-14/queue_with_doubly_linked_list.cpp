#include <bits/stdc++.h>
using namespace std;

// ABSTRACT DATA STRUCTURE

/*
    q.push() -> O(1) -> enqueue
    q.pop() -> O(1) -> denqueue
    q.front() -> O(1)
    q.sz() -> O(1)
    q.empty() -> O(1)
 */

// IMPLEMENTATION USING DOUBLY LINKED LIST
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
        
        if(head == NULL) {
            tail = NULL;
            return;
        }

        // !important -> This must be added after the edge case
        head->prev = NULL;
    }

    int front()
    {
        return head->val;
    }
    int back()
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

int main()
{

    int n;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        q.push(v);
    }

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}