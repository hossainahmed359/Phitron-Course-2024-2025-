#include <bits/stdc++.h>
using namespace std;

int n, e;
int adj_mat[1005][1005];

void FLOYD_WARSHALL() /* v^3  || n^3 */
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // i -> k -> j < i -> j
                int c_ij = adj_mat[i][j],
                    c_ik = adj_mat[i][k],
                    c_kj = adj_mat[k][j];

                if (c_ik != INT_MAX && c_kj != INT_MAX && c_ik + c_kj < c_ij)
                    adj_mat[i][j] = c_ik + c_kj;
            }
        }
    }
}

void detectNegativeCycle()
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[i][i] < 0) /* the value of moving i -> i is 0 */
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "Negative Cycle Found!" << endl;
    else
        cout << "No Negative Cycle Found!" << endl;
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; /* Undirected Graph */
    }

    FLOYD_WARSHALL();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = adj_mat[i][j];
            if (val == INT_MAX)
                cout << "I  ";
            else
                cout << val << "  ";
        }
        cout << endl;
    }

    detectNegativeCycle();

    return 0;
}

/*

Input:
4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

Output:
0  3  5  8  
I  0  2  5  
I  I  0  4  
I  I  I  0  
No Negative Cycle Found!


Input:
4 4
0 1 5
1 2 3
2 3 2
3 1 -6


Output:
0  4  7  9  
I  -1  2  4  
I  -4  -1  1  
I  -7  -4  -2  
Negative Cycle Found!


*/
