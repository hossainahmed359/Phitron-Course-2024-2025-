// Question: Take a queue of size N as input. You need to copy those elements in another queue in reverse order. You might use stack here. You should use STL to solve this problem. After copying in another queue, print the elements of that queue.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    queue<int> q, qReverse;
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        qReverse.push(s.top());
        s.pop();
    }
    
    while (!qReverse.empty())
    {
        cout << qReverse.front() << " ";
        qReverse.pop();
    }

    return 0;
}