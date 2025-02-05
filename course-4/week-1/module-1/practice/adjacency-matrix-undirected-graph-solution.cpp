#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // Index Starts with 1 as first Node value 1
    int adj_mat[n + 1][n + 1]; /* Index 1 -> 7 */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1; // Directed
        adj_mat[b][a] = 1; // Un Directed
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj_mat[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Input
    6 Nodes 10 Edges
    6 10
    1 2
    1 5
    2 3
    2 4
    2 5
    3 4
    3 6
    4 5
    4 6
    5 6

*/