// Question: Take a stack of size N as input and copy those elements to another stack to get the values in the order they were inserted and print them. You should use STL to solve this problem.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    stack<int> s, s2;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s2.push(val);
        s.pop();
    }

    s = s2;

    while (!s.empty())
    {
        cout << s.top() << " ";
    }

    return 0;
}