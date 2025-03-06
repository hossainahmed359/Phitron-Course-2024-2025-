// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
// Knapsack

#include <bits/stdc++.h>
using namespace std;

// 0-1 Knapsack Problem
int n, max_weight;
int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
        return 0;

    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    if (weight[i] <= max_weight)
    {

        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, max_weight);

        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    }
    else
    {
        int op2 = knapsack(i - 1, max_weight);
        dp[i][max_weight] = op2;
        return dp[i][max_weight];
    }
}

int main()
{
    cin >> n >> max_weight;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> val[i] ;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, max_weight) << endl;

    return 0;
}

/*

Input:
3 8
3 30
4 50
5 60

*/