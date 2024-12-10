#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long int> arr(n + 1); // 1 based index
    vector<long long int> prefix_arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix_arr[i] = prefix_arr[i - 1] + arr[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long int sum = prefix_arr[r] - prefix_arr[l - 1];

        cout << sum << endl;
    }

    return 0;
}