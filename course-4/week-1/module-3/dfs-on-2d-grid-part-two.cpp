#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool freq[105][105];
vector<pair<int, int>> moveD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void dfs(int si, int sj) /*  O(N + E)   */
{
    cout << si << " " << sj << endl;

    freq[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + moveD[i].first;
        int cj = sj + moveD[i].second;

        if (valid(ci, cj) == true && freq[ci][cj] == false)
            dfs(ci, cj);
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj; 
    cin >> si >> sj;

    memset(freq, false, sizeof(freq));

    dfs(si, sj); /* 0 -> first node val */

    return 0;
}

/* INPUT

3 4
. . . .
. . . .
. . . .
1 2

 */

/* OUTPUT

1 2
0 2
0 1
1 1
2 1
2 0
1 0
0 0
2 2
2 3
1 3
0 3

 */