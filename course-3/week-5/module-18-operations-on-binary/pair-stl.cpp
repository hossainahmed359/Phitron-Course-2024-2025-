#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p;

    p = make_pair(2, 3);
    p = {121, 3434};

    cout << p.first << endl;
    cout << p.second << endl;

    int n = 5;
    vector<pair<int, int>> v(n); /* VECTOR OF PAIRS */
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    return 0;
}