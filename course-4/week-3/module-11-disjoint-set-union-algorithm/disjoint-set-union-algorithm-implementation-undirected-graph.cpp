#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node) /* o(longN) */
{
    if (par[node] == -1)
        return node;

    int lead = find(par[node]);
    par[node] = lead;

    return lead;
}

void dsu_union(int node1, int node2)
{
    int lead1 = find(node1);
    int lead2 = find(node2);

    if (group_size[lead1] >= group_size[lead2])
    {
        par[lead2] = lead1;
        group_size[lead1] += group_size[lead2];
    }
    else
    {
        par[lead1] = lead2;
        group_size[lead2] += group_size[lead1];
    }
}

int main()
{

    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;
    
    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leadA = find(a);
        int leadB = find(b);
        if (leadA == leadB)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "Cycle Detected\n" << endl;
    else
        cout << "No Cycle Detected\n" << endl;

    return 0;
}

/*
Input:
6 6
0 1
1 2
0 4
4 5
5 3
3 4


 */