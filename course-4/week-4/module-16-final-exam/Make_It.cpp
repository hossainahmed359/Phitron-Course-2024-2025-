// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-it-2
// Make It

#include <bits/stdc++.h>
using namespace std;

void make_it(int i, int n, vector<bool> &freq)
{
    // cout << "i : " << i << ", n: " << n << endl;

    if (i >= n || freq[n] || freq[i])
    {
        freq[i] = true;
        return;
    }

    freq[i] = true;

    make_it(i + 3, n, freq);
    make_it(i * 2, n, freq);
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<bool> freq(1000000, false);

        make_it(1, n, freq);

        if (freq[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*

Level 0:                     1
Level 1:                 /       \
Level 2:                4         2
Level 3:             /   \       /   \
Level 4:           7      8     5      4
Level 5:         / \    / \    / \    / \
Level 6:       10  14 11 16   8  10  7   8




*/