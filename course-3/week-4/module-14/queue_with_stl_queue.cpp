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

// IMPLEMENTATION USING STL QUEUE

int main()
{

    int n;
    cin >> n;

    queue<int>q;

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