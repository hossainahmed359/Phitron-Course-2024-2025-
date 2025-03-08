// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/pile-of-word-37-3
// Pile of Word

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_pile(string a, string b)
{
    if (a.length() != b.length())
        return false;

    vector<int> freq_a(26, 0);
    vector<int> freq_b(26, 0);

    for (char x : a)
        freq_a[x - 'a'] += 1;

    for (char y : b)
        freq_b[y - 'a'] += 1;

    bool flag = true;

    for (int i = 0; i <= 25; i++)
    {
        if (freq_a[i] != freq_b[i])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        bool flag = check_pile(a, b);
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
