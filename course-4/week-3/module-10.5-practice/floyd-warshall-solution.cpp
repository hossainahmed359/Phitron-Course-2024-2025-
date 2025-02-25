// https://cses.fi/problemset/task/1672/
// Shortest Routes II

#include <bits/stdc++.h>
using namespace std;

int n, m, q;
long long adj_mat[1005][1005];

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

                if (ik != LLONG_MAX && kj != LLONG_MAX && ik + kj < ij)
                    adj_mat[i][j] = ik + kj;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while (m--)
    {
        int a, b;
        long long int c;

        cin >> a >> b >> c;

        if (c < adj_mat[a][b])
            adj_mat[a][b] = c;

        if (c < adj_mat[b][a])
            adj_mat[b][a] = c;
    }

    FLOYD_WARSHALL();

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (adj_mat[a][b] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[a][b] << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (adj_mat[i][j] == LLONG_MAX)
    //             cout << "I ";
    //         else
    //             cout << adj_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}