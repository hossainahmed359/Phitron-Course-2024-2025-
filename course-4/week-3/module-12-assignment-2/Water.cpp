// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/water-4-1
// Water

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> height(n);

        for (int i = 0; i < n; i++)
        {
            long long int h;
            cin >> h;
            height[i] = h;
        }

        int max_index = 0;
        for (int i = 1; i < n; i++)
        {
            if (height[i] > height[max_index])
                max_index = i;
        }
        int second_max_index;
        if (max_index == 0)
            second_max_index = 1;
        else
            second_max_index = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != max_index && height[i] > height[second_max_index])
                second_max_index = i;
        }

        if (second_max_index < max_index)
            cout << second_max_index << " " << max_index << endl;
        else
            cout << max_index << " " << second_max_index << endl;
    }

    return 0;
}
