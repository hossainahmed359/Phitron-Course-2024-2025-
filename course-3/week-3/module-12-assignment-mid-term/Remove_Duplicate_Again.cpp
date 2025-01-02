// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges/remove-duplicate-again
// Remove Duplicate Again

#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        l.push_back(val);
    }

    l.sort();
    l.unique();

    for (int val : l)
    {
        cout << val << " ";
    }

    return 0;
}
