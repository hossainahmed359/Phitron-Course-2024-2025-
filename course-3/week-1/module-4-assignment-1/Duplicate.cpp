// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges/duplicate-12
// Duplicate

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (i != j && a[i] == a[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            break;
        }
    }

    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
