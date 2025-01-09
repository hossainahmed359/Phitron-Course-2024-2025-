// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges/is-it-valid-1-1
// Is It Valid

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> stk;

        for (auto ch : s)
        {
            if (!stk.empty() && ch == '0' && stk.top() == '1')
            {
                stk.pop();
            }
            else if (!stk.empty() && ch == '1' && stk.top() == '0')
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }

        if (stk.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
