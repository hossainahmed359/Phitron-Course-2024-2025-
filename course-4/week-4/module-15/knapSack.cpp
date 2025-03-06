#include <bits/stdc++.h>
using namespace std;

// 0-1 Knapsack Problem
int n, max_weight;
int val[1005], weight[1005];

int knapsack(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
        return 0;

    if (weight[i] <= max_weight)
    {

        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, max_weight);
        return max(op1, op2);
    }
    else
    {
        int op2 = knapsack(i - 1, max_weight);
        return op2;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> max_weight;

    cout << knapsack(n - 1, max_weight) << endl;

    return 0;
}

/*

Input:
4
10 4 7 5
4 3 2 5
8

*/