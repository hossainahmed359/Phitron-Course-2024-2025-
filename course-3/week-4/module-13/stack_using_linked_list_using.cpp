#include <bits/stdc++.h>
using namespace std;

/*
    st.push() -> O(1)
    st.pop() -> O(1)
    st.top() -> O(1)
    st.size() -> O(1)
    st.empty() -> O(1)
 */

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

class Stack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int len = 0;

    void push(int val)
    {
        len++;
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
        len--;
        Node *tmp = tail;
        tail = tmp->prev;
        delete tmp;

        if (tail == NULL)
        {
            head = NULL;
            return;
        }

        tail->next = NULL;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return len;
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

    Stack st;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        st.push(v);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}