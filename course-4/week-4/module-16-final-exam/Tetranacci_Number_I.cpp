// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number-a-easy-version
// Tetranacci Number I

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
T0 = 0, T1 = 1, T2 = 1,T3 = 2
For  , Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
*/

int n;
vector<long long int> series(105, -1);

int tetranacci(int n)
{
    if (n <= 3)
        return series[n];

    if (series[n] != -1)
        return series[n];

    series[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);

    return series[n];
}

int main()
{
    series[0] = 0, series[1] = 1, series[2] = 1, series[3] = 2;
    cin >> n;

    long long int val = tetranacci(n);
    cout << val << endl;

    return 0;
}
