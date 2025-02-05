#include <bits/stdc++.h>
using namespace std;

// Adjacency Matrix of Undirected Graph

/*
      0
    / | \
   1  |  2
    \ |
     3 --- 4

    Nodes -> 5
    Edges -> 5

    Input ->
        Nodes , Edges ->
            5  5
        Connections ->  (As it is UNDIRECTED)
            0  1  && 1  0
            0  2  && 2  0
            3  0  && 0  3
            1  3  && 1  3
            3  4  && 4  3

    Final Input ->
            5  5
            0  1
            0  2
            3  0
            1  3
            3  4
 */

/*
    Matrix Input 0, 1 && 1, 0 row -> col
        0  1  1  1  0
        1  0  0  1  0
        1  0  0  0  0
        1  0  0  0  1
        0  0  0  1  0
 */
/*
    Matrix Input Note: Diagonal values are 1 because we can move from 1 -> 1 , 2 -> 2 , 3 -> 3, 4 -> 4, 5 -> 5 (Will not be mentioned in input, needs to be done manually)
        1  1  1  1  0
        1  1  0  1  0
        1  0  1  0  0
        1  0  0  1  1
        0  0  0  1  1
 */

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    /* set all r, c val to 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj_mat[i][j] = 0;
            }

        }
    */

    // Shorthand to r,c -> 0
    memset(adj_mat, 0, sizeof(adj_mat));

    // Set Diagonal Values to 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 1;
        }

    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_mat[a][b] = 1; /* directed */
        adj_mat[b][a] = 1; /* undirected */
    }

    // PRINT
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << "  ";
        }

        cout << endl;
    }

    return 0;
}

/* 
    Best useage: 
        Can find the connection between two nodes in O(1) , such as connection between 3, 4 
 */