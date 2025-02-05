#include <bits/stdc++.h>
using namespace std;

// Adjacency List of Undirected Graph

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
            0  1  && 1  0
            0  2  && 2  0
            3  0  && 0  3
            1  3  && 3  1
            3  4  && 4  3

    Final Input ->
            5  5
            0  1
            0  2
            3  0
            1  3
            3  4

    [ 0, 1, 2, 3, 4 ] -> 5 Nodes
    [
        0 -> 1 , 2, 3  // 0 -> 1 , 0 -> 2
        1 -> 0, 3      // 1 -> 0, 1 -> 3
        2 -> 0         // 2 -> 0
        3 -> 0, 1, 4   // 3 -> 0, 3 -> 1, 3 -> 4
        4-> 3          // 4 -> 3
    ]

    Final Output
    [ 0, 1, 2, 3, 4 ] -> 5 Nodes
    [
        0 -> [ 1 , 2, 3 ]
        1 -> [ 0, 3 ]
        2 -> [ 0 ]
        3 -> [ 0, 1, 4 ]
        4->  [ 3 ]
    ]
    
    [  0, 1, 2, 3, 4  ] 
       ↓  ↓  ↓  ↓  ↓
       1  0  0  0  3
       2  3     1
       3        4

    0 -> 1  2  3  
    1 -> 0  3  
    2 -> 0  
    3 -> 0  1  4  
    4 -> 3  
 */

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n]; // arr of vector

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // directed
        adj_list[b].push_back(a); // undirected
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj_list[i])
        {
            cout << x << "  ";
        }

        cout << endl;
    }

    return 0;
}

/* 
    Best useage: 
        Can find which nodes are connected on a node, such as finding which nodes are connected with node 3 -> 0 , 1, 4 O(n)  -> to find which nodes are connected and O(n) -> to print
 */