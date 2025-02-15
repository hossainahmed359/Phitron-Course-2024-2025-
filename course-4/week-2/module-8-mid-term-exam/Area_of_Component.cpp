// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/area-of-component
// Area of Component

#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[1005][1005];
bool freq[1005][1005];

vector<pair<int, int>> move_axis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int current_area = 0;

void DFS(int si, int sj)
{
    freq[si][sj] = true;
    current_area++;

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

    int min_area = INT_MAX;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!freq[i][j] && grid[i][j] == '.')
            {
                flag = true;
                current_area = 0;
                DFS(i, j);
                if (current_area != 0 && current_area < min_area)
                    min_area = current_area;
            }
        }
    }

    if (!flag)
        cout << -1 << endl;
    else
        cout << min_area << endl;

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