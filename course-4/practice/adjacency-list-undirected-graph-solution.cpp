#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n + 1];

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // Directed
        adj_list[b].push_back(a); // Un Directed
    }

    for (int i = 1; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Input
    6 Nodes 10 Edges
    6 10
    1 2
    1 5
    2 3
    2 4
    2 5
    3 4
    3 6
    4 5
    4 6
    5 6

*/