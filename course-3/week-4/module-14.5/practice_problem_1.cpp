// Question: Take two stacks of size N and M as input and check if both of them are the same or not. Don’t use STL to solve this problem.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    stack<int> a, b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        a.push(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        b.push(val);
    }

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;

    while (!(a.empty() && b.empty()))
    {
        if (a.top() != b.top())
        {
            flag = false;
            break;
        }
        a.pop();
        b.pop();
    }

    // flag = (a.empty() && b.empty());

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    // SHORTCUT WAY
    // flag = a == b;

    return 0;
}