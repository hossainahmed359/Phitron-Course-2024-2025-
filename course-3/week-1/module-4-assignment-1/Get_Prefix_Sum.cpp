// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges/get-prefix-sum
// Get Prefix Sum

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long int> a(n);
    vector<long long int> prefix_sum_a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            prefix_sum_a[i] = a[i];
        }
        else
        {
            prefix_sum_a[i] = prefix_sum_a[i - 1] + a[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << prefix_sum_a[i] << " ";
    }
    

    return 0;
}
