// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number
// Tetranacci Number II

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<long long int> series(105, -1);

int main()
{
    series[0] = 0, series[1] = 1, series[2] = 1, series[3] = 2;
    cin >> n;

    if (n <= 3)
    {
        cout << series[n] << endl;
        return 0;
    }

    for (int i = 4; i <= n; i++)
    {
        series[i] = series[i - 1] + series[i - 2] + series[i - 3] + series[i - 4];
    }

    cout << series[n] << endl;

    return 0;
}
