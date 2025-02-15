// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2
// Knight Moves

#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[105][105];
bool freq[105][105];

vector<pair<int, int>> move_axis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int steps = 0;

void DFS(int si, int sj)
{
    freq[si][sj] = true;
    steps++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + move_axis[i].first;
        int cj = sj + move_axis[i].second;

        if (valid_axis(ci, cj) && !freq[ci][cj] && grid[ci][cj] == '.')
            DFS(ci, cj);
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
        }
    }

    memset(freq, false, sizeof(freq));
    memset(freq, 0, sizeof(freq));

    int min_steps = INT_MAX;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!freq[i][j])
            {
                //
            }
        }
    }

    if (!flag)
        cout << -1 << endl;
    else
        cout << min_steps << endl;

    return 0;
}


/* 
6 5
..-..
..-..
-----
.-...
.----
.....

-> Output -> 3

3 3
---
---
---

-> Output -> -1

*/