// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/give-max-min
// Give Current Min

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq_min;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pq_min.push(val);
    }

    int q; /* Number of queries */
    cin >> q;
    while (q--)
    {

        /*
            0 -> input int x &  print current min,
            1 -> print current min,
            2 -> delete current min & print current min after deletion
        */
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            long long int x;
            cin >> x;
            pq_min.push(x);
            cout << pq_min.top() << endl;
        }
        else if (cmd == 1)
        {
            if (pq_min.empty())
            {
                cout << "Empty" << endl;
                continue;
            }

            cout << pq_min.top() << endl;
        }
        else if (cmd == 2)
        {

            if (!pq_min.empty())
            {
                pq_min.pop();
            }

            if (pq_min.empty())
            {
                cout << "Empty" << endl;
                continue;
            }

            cout << pq_min.top() << endl;
        }
    }

    return 0;
}
