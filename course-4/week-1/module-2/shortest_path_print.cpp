#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool freq[1005];
int level[1005];
int parentNodes[1005];

void bfs(int src) /*  O(N + E)   */
{
    queue<int> que;
    que.push(src);
    freq[src] = true;

    level[src] = 0;
    parentNodes[src] = -1;

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

            level[child] = level[parent] + 1;
            parentNodes[child] = parent;
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
    memset(level, -1, sizeof(level));
    memset(parentNodes, -1, sizeof(parentNodes));

    int src, des;
    cin >> src >> des;

    bfs(src);

    cout << endl;
    cout << endl;

    cout << "printing levels" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << level[i] << endl;
    }

    cout << "shortest path from " << src << " to " << des << " is -> " << level[des] << endl;

    cout << endl;

    cout << "printing parentNodes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << parentNodes[i] << endl;
    }

    cout << endl;

    vector<int> path;
    int node = des;
    while (node != -1)
    {
        path.push_back(node);
        node = parentNodes[node];
    }

    reverse(path.begin(), path.end());

    cout << "route : ";
    for (int x : path)
    {
        cout << x << " -> ";
    }

    return 0;
}

/*

7 7

0 1
1 2
2 3
3 4
4 5
5 6
2 6

0 6


 */

/*

0 1 2 3 6 4 5 

printing levels
0 -> 0
1 -> 1
2 -> 2
3 -> 3
4 -> 4
5 -> 4
6 -> 3
shortest path from 0 to 6 is -> 3

printing parentNodes
0 -> -1
1 -> 0
2 -> 1
3 -> 2
4 -> 3
5 -> 6
6 -> 2

route : 0 -> 1 -> 2 -> 6 -> 

 */