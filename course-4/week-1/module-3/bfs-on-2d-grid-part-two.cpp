#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
int level[105][105];
bool freq[105][105];
vector<pair<int, int>> moveD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj) /*  O(N + E)   */
{
    queue<pair<int, int>> que;

    que.push({si, sj});

    freq[si][sj] = true;
    level[si][sj] = 0;

    while (!que.empty())
    {
        pair<int, int> par = que.front();
        que.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + moveD[i].first;
            int cj = par_j + moveD[i].second;

            if (valid(ci, cj) && freq[ci][cj] == false)
            {
                que.push({ci, cj});
                freq[ci][cj] = true;
                level[ci][cj] =  level[par_i][par_j] + 1;
            }
        }
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

    int si, sj, di, dj; /* s -> source , d-> destination */
    cin >> si >> sj >> di >> dj;

    memset(freq, false, sizeof(freq));
    memset(level, -1, sizeof(level));

    bfs(si, sj); /* 0 -> first node val */

    cout << "shortest path: " << level[di][dj] << endl;

    return 0;
}

/* INPUT

3 4
. . . .
. . . .
. . . .
1 2
2 0

 */

/* OUTPUT

1 2
0 2
2 2
1 1
1 3
0 1
0 3
2 1
2 3
1 0
0 0
2 0

 */