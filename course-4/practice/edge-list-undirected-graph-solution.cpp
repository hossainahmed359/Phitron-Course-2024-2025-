#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edge_list;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    for (int i = 0; i < e; i++)
    {
        cout << i << " -> ";
        cout << edge_list[i].first << "  " << edge_list[i].second << endl;
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