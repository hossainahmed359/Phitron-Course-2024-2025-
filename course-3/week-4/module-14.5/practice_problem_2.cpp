// Question: Take a stack of size N and a queue of size M as input. Then check if both of them are the same or not in the order of removing. You should use STL to solve this problem.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    stack<int> s;
    queue<int> q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    /*
        stack s->
        50
        40
        30
        20
        10
    */
    /*
        queue q->
        10 20 30 40 50
    */

    bool flag = true;

    while (!(s.empty() && q.empty()))
    {
        if (s.top() != q.front())
        {
            flag = false;
            break;
        }

        s.pop();
        q.pop();
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