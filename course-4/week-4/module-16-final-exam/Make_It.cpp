// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-it-2
// Make It

#include <bits/stdc++.h>
using namespace std;

vector<bool> freq(100005, false);

void make_it(int i, int n)
{
    cout << "i : " << i << ", n: " << n << endl;

    if (i > n || freq[n])
    {
        return;
    }
    freq[i] = true;

    make_it(i + 3, n);
    make_it(i * 2, n);
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        make_it(1, n);

        if (freq[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
