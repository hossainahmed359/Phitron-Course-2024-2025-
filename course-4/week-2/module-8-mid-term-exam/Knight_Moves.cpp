// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2/submissions/code/1388677837
// Knight Moves
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ki, kj, qi, qj; /* k -> source, q -> destination */

// int grid[1005][1005];
bool freq[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> move_axis = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void BFS(int si, int sj)
{
    queue<pair<int, int>> que;
    que.push({si, sj});
    freq[si][sj] = true;

    while (!que.empty())
    {
        pair<int, int> par = que.front();
        int par_i = par.first;
        int par_j = par.second;
        que.pop();

        for (int i = 0; i < 8; i++)
        {
            int child_i = par_i + move_axis[i].first;
            int child_j = par_j + move_axis[i].second;

            if (valid_axis(child_i, child_j) && !freq[child_i][child_j])
            {
                que.push({child_i, child_j});
                freq[child_i][child_j] = true;
                parent[child_i][child_j] = {par_i, par_j};
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> ki >> kj >> qi >> qj;

        // memset(grid, 0, sizeof(grid));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                parent[i][j] = {-1, -1};
            }
        }

        memset(freq, false, sizeof(freq));

        BFS(ki, kj);

        if (!freq[qi][qj])
            cout << -1 << endl;
        else
        {
            vector<pair<int, int>> path;
            int i = qi, j = qj;
            while (!(i == ki && j == kj))
            {
                path.push_back({i, j});

                int temp_i = parent[i][j].first;
                int temp_j = parent[i][j].second;

                i = temp_i;
                j = temp_j;
            }

            path.push_back({ki, kj});

            reverse(path.begin(), path.end());

            cout << path.size() - 1 << endl;
        }
    }

    return 0;
}


/* 
Input -> 
4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1

Output -> 
6
0
3
-1

*/