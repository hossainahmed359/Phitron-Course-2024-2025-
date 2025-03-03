// http://cses.fi/problemset/task/1676/
// Road Construction

#include <bits/stdc++.h>
using namespace std;

vector<int> par(100005, -1);
vector<int> group_size(100005, 1);
int cmp, max_comp;

int find_lead(int node)
{
    if (par[node] == -1)
        return node;

    int lead = find_lead(par[node]);
    par[node] = lead;
    return lead;
}

void dsu_union(int node_one, int node_two)
{
    int lead_one = find_lead(node_one);
    int lead_two = find_lead(node_two);

    if (lead_one == lead_two)
        return;

    if (group_size[lead_one] >= group_size[lead_two])
    {
        par[lead_two] = lead_one;
        group_size[lead_one] += group_size[lead_two];
        max_comp = max(max_comp, group_size[lead_one]);
    }
    else
    {
        par[lead_one] = lead_two;
        group_size[lead_two] += group_size[lead_one];
        max_comp = max(max_comp, group_size[lead_two]);
    }

    cmp--;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cmp = n;
    max_comp = 1;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << max_comp << endl;
    }

    return 0;
}