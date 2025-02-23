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
        for (auto ed : edge_list)
        {
            int a = ed.a,
                b = ed.b,
                c = ed.c;

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

    // SET ALL DISTANCE TO MAX VALUE
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // SET FIRST NODE DISTANCE TO 0
    dis[0] = 0;

    BELLMAN_FORD();

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}

/*

Input:
4 4
0 2 5
0 3 12
2 1 2
1 3 3


Output:
0 -> 0
1 -> 7
2 -> 5
3 -> 10


*/
