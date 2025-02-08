// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-or-not-1-1
// Connected or Not

#include <bits/stdc++.h>
using namespace std;

int adj_mat[1005][1005];

void print_matrix(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    long int e;
    cin >> n >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
        }
    }

    // cout << "INITIALIZED ADJACENT MATRIX" << endl;
    // print_matrix(n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1; /* DIRECTED GRAPH */
    }

    // cout << "INITIALIZED ADJACENT MATRIX AFTER INPUT" << endl;
    // print_matrix(n);

    long int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (adj_mat[a][b] == 1 /* NODE IS CONNECTED */)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
5 6

0 1
1 2
2 3
3 4
1 4
0 2

1  1  1  0  0
0  1  1  0  1
0  0  1  1  0
0  0  0  1  1
0  0  0  0  1
*/