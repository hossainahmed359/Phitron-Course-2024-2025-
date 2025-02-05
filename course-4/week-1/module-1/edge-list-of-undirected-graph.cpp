#include <bits/stdc++.h>
using namespace std;

// Edge List of Undirected Graph

/*
      0
    / | \
   1  |  2
    \ |
     3 --- 4

    Nodes -> 5
    Edges -> 5

    Input ->
        Nodes , Edges ->
            5  5
        Connections ->  (As it is UNDIRECTED)
            0  1
            0  2
            3  0
            1  3
            3  4

    Final Input ->
            5  5
            0  1
            0  2
            3  0
            1  3
            3  4

    [ 0, 1, 2, 3, 4, 5 ]
    [
        [0 , 1],
        [0 , 2],
        [3 , 0],
        [1 , 3],
        [3 , 4],
    ]

    0 1
    0 2
    3 0
    1 3
    3 4
 */

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

    for (pair<int, int> p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

/* 
    Best useage: 
        If we need to only work with edge
 */