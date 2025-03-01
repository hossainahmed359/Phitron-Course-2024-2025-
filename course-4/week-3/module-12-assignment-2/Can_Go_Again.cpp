// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/can-go-again
// Can Go Again?

#include <bits/stdc++.h>
using namespace std;

class Edge
{

public:
    int a, b;
    long long int c;
    Edge(int a, int b, long long int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e, s, t, d;
vector<Edge> edge_list;
vector<long long int> dis(1005, LLONG_MAX);
bool negative_cycle = false;

void BELLMAN_FORD(int s)
{
    dis[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (Edge ed : edge_list)
        {
            int a = ed.a, b = ed.b;
            long long int c = ed.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for (Edge ed : edge_list)
    {
        int a = ed.a, b = ed.b;
        long long int c = ed.c;

        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            negative_cycle = true;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    cin >> s;

    BELLMAN_FORD(s);

    cin >> t;
    if (negative_cycle)
    {
        cout << "Negative Cycle Detected\n";
    }
    else
    {
        while (t--)
        {
            cin >> d;
            long long int min_dis = dis[d];
            if (min_dis == LLONG_MAX)
                cout << "Not Possible\n";
            else
                cout << min_dis << endl;
        }
    }

    return 0;
}


/* 
Input:
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5


Output:
0
-1
-2
-5
0



Input:
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5


Output:
5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5



Input:
5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5


Output:
Negative Cycle Detected


*/