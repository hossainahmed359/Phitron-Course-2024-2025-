#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<pair<int, int>>> adj_list(1005);
int dis[105];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    /*
        priority_queue default comparison works with the first value by default
        pq.first = distance
        pq.second = node val

    */

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();

        int par_node = par.second;
        int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node] /* path relaxation */)
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    // priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        cout << "node " << i << " : ";
        vector<pair<int, int>> vec = adj_list[i];
        for (pair<int, int> x : vec)
        {
            cout << "{" << x.first << ", " << x.second << "} ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    cout << endl;

    cout << "Printing All Shortest Distances: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Shortest Distance to " << i << " : " << dis[i] << endl;
    }

    return 0;
}

/*
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

*/