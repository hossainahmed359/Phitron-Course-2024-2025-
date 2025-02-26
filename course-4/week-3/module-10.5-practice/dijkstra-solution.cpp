#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<pair<int, int>>> adj_list(1005);
int dis[1005];

void DIJKSTRA(int src)
{
    queue<pair<int, int>> que;
    que.push({src, 0});
    dis[src] = 0;

    while (!que.empty())
    {
        pair<int, int> par = que.front();
        int par_node = par.first;
        int par_dis = par.second;

        que.pop();

        vector<pair<int, int>> vec = adj_list[par_node];
        for (pair<int, int> p : vec)
        {

            int child_node = p.first;
            int child_dis = p.second;

            if (dis[par_node] != INT_MAX && dis[par_node] + child_dis < dis[child_node])
            {
                dis[child_node] = dis[par_node] + child_dis;
                que.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
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
        vector<pair<int, int>> vec = adj_list[i];
        for (pair<int, int> pr : vec)
        {
            cout << i << " -- " << pr.first << " -> " << pr.second << endl;
        }
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    DIJKSTRA(0);

    cout << endl;
    cout << "All Shortest Distances: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

/*
Input:
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