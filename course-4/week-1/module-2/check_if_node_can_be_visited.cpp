#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool freq[1005];

void bfs(int src) /*  O(N + E)   */
{
    queue<int> que;
    que.push(src);
    freq[src] = true;

    while (!que.empty()) /* O(N) -> Nodes*/
    {
        int parent = que.front();
        que.pop();

        cout << parent << " ";

        for (int child : adj_list[parent]) /* O(E) -> Edges */
        {
            if (freq[child])
                continue;
            que.push(child);
            freq[child] = true;
        }
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

    int src, des;
    cin >> src >> des;

    bfs(src);

    cout << endl;

    if (freq[des] == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

/*

7 6

0 1
1 3
1 4
3 2
3 5
4 5

1 6

 */

/*

1 0 3 4 2 5
NO

 */