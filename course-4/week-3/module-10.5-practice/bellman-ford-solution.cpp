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
    cout << "BELLMAN_FORD start" << endl;
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        cout << "i-> " << i << endl;
        for (Edge el : edge_list)
        {
            int a = el.a,
                b = el.b,
                c = el.c;

            cout << "before: dis of " << b << " -> " << (dis[b] == INT_MAX ? "I" : to_string(dis[b])) << " || ";

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;

            cout << "after: dis of " << b << " -> " << (dis[b] == INT_MAX ? "I" : to_string(dis[b])) << endl;
        }

        cout << endl;
    }

    cout << "BELLMAN_FORD end" << endl;
    cout << endl;
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
        cout << "shortest dis of " << i << " -> " << dis[i] << endl;
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

Output:

BELLMAN_FORD start

i-> 0
before: dis of 1 -> I || after: dis of 1 -> 3
before: dis of 2 -> I || after: dis of 2 -> 6
before: dis of 2 -> 6 || after: dis of 2 -> 5
before: dis of 3 -> I || after: dis of 3 -> 8
before: dis of 3 -> 8 || after: dis of 3 -> 8

i-> 1
before: dis of 1 -> 3 || after: dis of 1 -> 3
before: dis of 2 -> 5 || after: dis of 2 -> 5
before: dis of 2 -> 5 || after: dis of 2 -> 5
before: dis of 3 -> 8 || after: dis of 3 -> 8
before: dis of 3 -> 8 || after: dis of 3 -> 8

i-> 2
before: dis of 1 -> 3 || after: dis of 1 -> 3
before: dis of 2 -> 5 || after: dis of 2 -> 5
before: dis of 2 -> 5 || after: dis of 2 -> 5
before: dis of 3 -> 8 || after: dis of 3 -> 8
before: dis of 3 -> 8 || after: dis of 3 -> 8

BELLMAN_FORD end

shortest dis of 0 -> 0
shortest dis of 1 -> 3
shortest dis of 2 -> 5
shortest dis of 3 -> 8



*/