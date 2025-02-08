// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-nodes-1
// Connected Nodes

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(1005);

void print_adj_vector(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << i << " ";
        vector<int> vec = adj_list[i];
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    long int e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); /* DIRECTED */
        adj_list[b].push_back(a); /* UNDIRECTED */
    }

    // print_adj_vector(n);

    long int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;

        vector<int> vec = adj_list[a];
        if (vec.size() <= 0)
        {
            cout << -1 << endl;
            continue;
        }

        sort(vec.begin(), vec.end(), greater<int>());

        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*

INPUT
6 8 ->  Nodes & Edges

0 4 -> Connections
0 5
4 2
4 3
5 3
2 0
0 1
1 3

6 -> Queries

0
1
2
3
4
5

OUTPUT
5 4 2 1
3 0
4 0
5 4 1
3 2 0
3 0

*/