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

// IMPLEMENTATION USING STL LIST

class Queue
{
public:
    list<int> l;

    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }
    int back()
    {
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
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