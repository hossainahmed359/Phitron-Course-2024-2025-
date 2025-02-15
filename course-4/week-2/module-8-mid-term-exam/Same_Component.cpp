// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/same-component
// Same Component

#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1005][1005];
int freq[1005][1005];

vector<pair<int, int>> move_axis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void DFS(int si, int sj)
{
    freq[si][sj] = true;

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

    memset(freq, 0, sizeof(freq));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    DFS(si, sj);

    if (freq[di][dj])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}