#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<int>> adj_list(1005);
int freq[1005];
int parent[1005];
bool cycle = false;

void BFS(int src)
{
    cout << "BFS -> ";

    queue<int> que;
    que.push(src);
    freq[src] = true;


    while (!que.empty())
    {
        int par = que.front();
        que.pop();

        cout << par << " ";

        for (int child : adj_list[par])
        {
            if (freq[child] && parent[par] != child)
                cycle = true;

            if (freq[child])
                continue;

            que.push(child);
            freq[child] = true;
            parent[child] = par;
        }
    }

    cout << endl;
}

int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(freq, false, sizeof(freq));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++)
    {
        if (!freq[i])
            BFS(i);
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
3 0
4 5

*/