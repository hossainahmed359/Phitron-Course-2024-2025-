// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges/same-or-not-ii
// Same or Not

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    stack<int> stA;
    queue<int> queB;

    // n -> stack , m -> queue

    cin >> n >> m;

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
