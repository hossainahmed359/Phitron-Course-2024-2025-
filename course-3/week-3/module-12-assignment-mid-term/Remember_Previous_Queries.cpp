// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges/remember-previous-queries
// Remember Previous Queries?

#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<long long int> l;

    int q;
    cin >> q;
    while (q--)
    {
        long long int x, v;
        cin >> x >> v;

        long long int len = l.size();

        if (x == 0)
        {
            l.push_front(v);
        }
        else if (x == 1)
        {
            l.push_back(v);
        }
        else if (x == 2 && (v >= 0 && v < len))
        {
            if (v == 0)
            {
                l.pop_front();
            }
            else if (v > 0 && v < len - 1)
            {
                auto idx = next(l.begin(), v);
                l.erase(idx);
            }
            else if (v == len - 1)
            {
                l.pop_back();
            }
        }

        cout << "L -> ";
        for (auto it : l)
        {
            cout << it << " ";
        }
        cout << endl;

        cout << "R -> ";
        long long int new_len = l.size();
        for (long long int i = new_len - 1; i >= 0; i--)
        {
            cout << *next(l.begin(), i) << " ";
        }

        cout << endl;
    }

    return 0;
}
