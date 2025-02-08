// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/can-go-1
// Can Go?

#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool freq[1005][1005];

vector<pair<int, int>> move_axis = {
    {0, -1}, /* -> left */
    {0, 1},  /* -> right */
    {-1, 0}, /* -> up */
    {1, 0},  /* -> down */
};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void print_grid(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;
    freq[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + move_axis[i].first;
        cj = sj + move_axis[i].second;
        if (valid_axis(ci, cj) && freq[ci][cj] == false && grid[ci][cj] != '#')
            dfs(ci, cj);
    }
}

int main()
{

    cin >> n >> m;
    int start_i = 0, start_j = 0, des_i = 0, des_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;

            if (ch == 'A')
            {
                start_i = i;
                start_j = j;
            }
            else if (ch == 'B')
            {
                des_i = i;
                des_j = j;
            }
        }
    }

    memset(freq, false, sizeof(freq));

    // print_grid(n, m);

    dfs(start_i, start_j);

    if (freq[des_i][des_j] == true)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

/*

. -> Floor
# -> Wall
A -> Current
B -> Destination

# # # # # # # #
# . A # . . . #
# . # # . # B #
# . . . . . . #
# # # # # # # #

1 2
1 1
2 1
3 1
3 2
3 3
3 4
3 5
3 6
2 6
1 6
1 5
1 4
2 4


*/