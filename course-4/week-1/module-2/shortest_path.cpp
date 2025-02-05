#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool freq[1005];
int level[1005];

void bfs(int src) /*  O(N + E)   */
{
    queue<int> que;
    que.push(src);
    freq[src] = true;

    level[src] = 0;

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

    int src, des;
    cin >> src >> des;

    bfs(src);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << level[i] << endl;
    }

    cout << "shortest path to " << des << " is -> " << level[des] << endl;

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
0 -> 0
1 -> 1
2 -> 2
3 -> 3
4 -> 4
5 -> 4
6 -> 3
shortest path to 6 is -> 3

 */