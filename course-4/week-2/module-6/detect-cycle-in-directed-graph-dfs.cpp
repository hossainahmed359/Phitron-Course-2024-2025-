#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<int>> adj_list(1005);
int freq[1005];
int path[1005];
bool cycle = false;

void DFS(int src)
{
    cout << src << " ";

    freq[src] = true;
    path[src] = true;

    for (int child : adj_list[src])
    {
        if (freq[child] && path[child])
            cycle = true;

        if (!freq[child])
            DFS(child);
    }

    path[src] = false;
}

int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    memset(freq, false, sizeof(freq));
    memset(path, false, sizeof(path));

    for (int i = 0; i < n; i++)
    {
        if (!freq[i])
        {
            cout << "DFS ";
            DFS(i);
            cout << endl;
        }
    }

    if (cycle)
        cout << "Cycle Detected";
    else
        cout << "No Cycle Detected";

    return 0;
}

/*

6 5
0 1
1 2
2 3
0 3
4 5

*/