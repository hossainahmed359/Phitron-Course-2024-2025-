// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges/special-queries-1-1
// Special Queries

#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> que;

    int q;
    cin >> q;

    while (q--)
    {
        int val;
        cin >> val;

        if (val == 0)
        {
            string name;
            cin.ignore();
            getline(cin, name);
            que.push(name);
        }
        else if (val == 1)
        {
            if (que.empty())
            {
                cout << "Invalid" << endl;
            }
            else
            {
                string frontName = que.front();
                cout << frontName << endl;
                que.pop();
            }
        }
    }

    return 0;
}
