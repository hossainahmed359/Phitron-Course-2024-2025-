// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/count-apartments
// Count Apartments || 

#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool freq[1005][1005];

vector<pair<int, int>> move_axis = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0},
};

bool valid_axis(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj, int &count)
{
    freq[si][sj] = true;
    count++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + move_axis[i].first;
        int cj = sj + move_axis[i].second;
        if (valid_axis(ci, cj) && freq[ci][cj] == false && grid[ci][cj] != '#')
            dfs(ci, cj, count);
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

    vector<int> count_vec;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '#' && freq[i][j] == false)
            {
                int count = 0;
                dfs(i, j, count);
                count_vec.push_back(count);
            }
        }
    }

    if (count_vec.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(count_vec.begin(), count_vec.end());

    for (int x : count_vec)
        cout << x << " ";

    return 0;
}
