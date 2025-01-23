// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/sorted-3-1
// Sorted

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t; /* Number of queries */
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        set<int> st;
        while (n--)
        {
            int val;
            cin >> val;
            st.insert(val);
        }

        for (auto i : st)
        {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}
