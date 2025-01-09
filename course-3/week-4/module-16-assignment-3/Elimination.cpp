// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges/elimination-2-2
// Elimination

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        stack<char> stk;
        for (auto ch : str)
        {
            if (stk.empty())
            {
                stk.push(ch);
            }
            else if (ch == '0')
            {
                stk.push(ch);
            }
            else if (ch == '1' && stk.top() == '0')
            {
                stk.pop();
            }
        }

        if (stk.empty())
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
