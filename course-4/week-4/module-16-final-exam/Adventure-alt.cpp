#include <bits/stdc++.h>
using namespace std;

int knapsack(int i, int mx_weight, vector<pair<int, int>> &vec, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    int val = vec[i].first;
    int weight = vec[i].second;

    if (mx_weight - weight < 0)
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight, vec, dp);
        return dp[i][mx_weight];
    }

    int a = knapsack(i - 1, mx_weight - weight, vec, dp) + val;
    int b = knapsack(i - 1, mx_weight, vec, dp);
    dp[i][mx_weight] = max(a, b);
    return dp[i][mx_weight];
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, mx_weight;
        cin >> n >> mx_weight;
        vector<pair<int, int>> knapsack_arr(n); /* first -> val , second -> weight */

        for (int i = 0; i < n; i++)
            cin >> knapsack_arr[i].second;

        for (int i = 0; i < n; i++)
            cin >> knapsack_arr[i].first;

        vector<vector<int>> dp(n, vector<int>(mx_weight + 1, -1));

        int max_val = knapsack(n - 1, mx_weight, knapsack_arr, dp);
        cout << max_val << endl;
    }

    return 0;
}