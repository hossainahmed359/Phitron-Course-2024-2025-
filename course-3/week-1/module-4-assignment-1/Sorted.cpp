// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges/sorted-2-2
// Sorted

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    flag = false;
                    break;
                }
            }

            if (!flag)
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
    }

    return 0;
}
