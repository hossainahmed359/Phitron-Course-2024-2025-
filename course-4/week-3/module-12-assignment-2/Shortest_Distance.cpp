// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/shortest-distance-2
// Shortest Distance

#include <bits/stdc++.h>
using namespace std;

int n, e, q;
long long int adj_mat[1005][1005];

void FLOYD_WARSHALL()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long int
                    ik = adj_mat[i][k],
                    kj = adj_mat[k][j],
                    ij = adj_mat[i][j];

                if (ik == LLONG_MAX || kj == LLONG_MAX)
                    continue;

                if (ik + kj < ij)
                    adj_mat[i][j] = ik + kj;
            }
        }
    }
}

int main()
{
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj_mat[i][j] = LLONG_MAX;

    for (int i = 1; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;

        if (c < adj_mat[a][b])
            adj_mat[a][b] = c;
    }

    FLOYD_WARSHALL();

    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        long long int min_dis = adj_mat[a][b];

        if (min_dis == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << min_dis << endl;
    }

    return 0;
}
