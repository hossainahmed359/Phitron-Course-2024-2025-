// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Z
// Z. Binary Search

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (q--)
    {
        long int target;
        cin >> target;

        bool flag = false;

        int left = 0, right = n - 1;
        while (left <= right)
        {

            int mid = (left+ right) / 2;

            if(a[mid] == target) {
                flag = true;
                break;
            } else if(a[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if(flag) {
            cout << "found" << endl;
        } else {
            cout << "not found" << endl;

        }
    }

    return 0;
}