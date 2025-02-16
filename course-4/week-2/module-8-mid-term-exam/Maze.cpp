// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/maze-19
// Maze
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ri, rj, di, dj; /* r -> source, d -> destination */

char grid[1005][1005];
bool freq[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> move_axis = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

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

            if (valid_axis(child_i, child_j) && !freq[child_i][child_j] && grid[child_i][child_j] != '#')
            {
                que.push({child_i, child_j});
                freq[child_i][child_j] = true;
                parent[child_i][child_j] = {par_i, par_j};
            }
        }
    }
}

void print_grid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch = grid[i][j];
            cout << ch;
        }
        cout << endl;
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;

            grid[i][j] = ch;
            parent[i][j] = {-1, -1};

            if (ch == 'R')
                ri = i, rj = j;

            if (ch == 'D')
                di = i, dj = j;
        }
    }

    // print_grid();

    // cout << "move path: " << ri << " " << rj << " -> " << di << " " << dj << endl;

    memset(freq, false, sizeof(freq));

    BFS(ri, rj);

    if (freq[di][dj])
    {
        vector<pair<int, int>> path;
        int i = di, j = dj;
        while (!(i == ri && j == rj))
        {
            path.push_back({i, j});

            int temp_i = parent[i][j].first;
            int temp_j = parent[i][j].second;

            i = temp_i;
            j = temp_j;
        }

        path.push_back({ri, rj});

        reverse(path.begin(), path.end());

        for (auto x : path)
        {
            int xi = x.first;
            int xj = x.second;
            if (grid[xi][xj] == '.')
                grid[xi][xj] = 'X';
        }
    }

    print_grid();

    return 0;
}

/*
Input ->

5 6
...D.#
.##..#
....#.
.R#...
.#.##.

Output ->

...D.#
.##X.#
.XXX#.
.R#...
.#.##.

*/