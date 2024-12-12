// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges/insert-the-vector
// Insert it

#include <bits/stdc++.h>

using namespace std;

int main()
{

    // Input n, a
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Input m, b
    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // Input Index of array a
    int x;
    cin >> x;

    // Insert at index x
    a.insert(a.begin() + x, b.begin(), b.end());

    // Final Output
    for (auto it : a)
    {
        cout << it << " ";
    }

    return 0;
}
