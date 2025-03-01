// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/cycle-of-edges
// Cycle of Edges

#include <bits/stdc++.h>
using namespace std;

int n, e;
int cycle_count = 0;
vector<int> par(100005, -1);
vector<int> group_size(100005, 1);

int find_lead(int node)
{
    if (par[node] == -1)
        return node;

    int lead = find_lead(par[node]);
    par[node] = lead;

    return lead;
}

void dsu_union(int node_a, int node_b)
{
    int lead_a = find_lead(node_a);
    int lead_b = find_lead(node_b);

    if (group_size[lead_a] >= group_size[lead_b])
    {
        par[lead_b] = lead_a;
        group_size[lead_a] += group_size[lead_b];
    }
    else
    {
        par[lead_a] = lead_b;
        group_size[lead_b] += lead_a;
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int lead_a = find_lead(a),
            lead_b = find_lead(b);

        if (lead_a == lead_b)
            cycle_count++;
        else
            dsu_union(a, b);
    }

    cout << cycle_count << endl;

    return 0;
}
