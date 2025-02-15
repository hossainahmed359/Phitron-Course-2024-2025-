#include<bits/stdc++.h>
using namespace std;

int n, e;
vector < vector < int >> adj_list(1005);
int freq[1005];
int parent[1005];
bool cycle = false;

void DFS(int src) {
    cout << src << " ";

    freq[src] = true;

    for (int child : adj_list[src]) {
        if (freq[child] && parent[src] != child)
            cycle = true;

        if (freq[child])
            continue;

        parent[child] = src;
        DFS(child);
    }

}


int main() {

    cin >> n >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(freq, false, sizeof(freq));
    memset(parent, -1, sizeof(parent));

    for(int i = 0;i < n; i++) {
        if(!freq[i]) {
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
3 0
4 5

*/