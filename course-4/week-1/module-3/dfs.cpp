#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool freq[1005];

void dfs(int src) /*  O(N + E)   */
{
    cout << src << " ";
    freq[src] = true;
    for (int child : adj_list[src])
    {
        if (freq[child] == false)
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    // vector<int> adj_list[n]; // arr of vector

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // directed
        adj_list[b].push_back(a); // undirected
    }

    memset(freq, false, sizeof(freq));

    dfs(0); /* 0 -> first node val */

    return 0;
}

/*

7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5

 */

/*

0 1 3 4 2 5 6

 */