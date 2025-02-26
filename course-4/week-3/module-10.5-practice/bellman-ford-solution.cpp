#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
vector<Edge> edge_list;
int dis[1005];

void BELLMAN_FORD()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge el : edge_list)
        {
            int a = el.a,
                b = el.b,
                c = el.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
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
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            dis[0] = 0;
        else
            dis[i] = INT_MAX;
    }

    BELLMAN_FORD();

    for (int i = 0; i < n; i++)
    {
        cout << "shortest distance " << i << " : " << dis[i] << endl;
    }

    return 0;
}

/*
Input:
4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

*/