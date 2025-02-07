#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool freq[105][105];
vector<pair<int, int>> moveD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int si, int sj) /*  O(N + E)   */
{
    cout << si << " " << sj << endl;

    freq[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + moveD[i].first;
        cj = sj + moveD[i].second;
        cout << ci << " " << cj << endl;
    }
}

int main()
{

    int n, m;
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
2 2
1 1
1 3

 */