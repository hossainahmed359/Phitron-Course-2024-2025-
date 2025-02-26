//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dis(V);
        bool cycle = false;
        const int max_int = 100000000;

        for (int i = src; i < V; i++)
        {
            if (i == src)
                dis[i] = 0;
            else
                dis[i] = max_int;
        }

        for (int i = src; i < V; i++)
        {
            for (vector<int> vec : edges)
            {
                int a = vec[0],
                    b = vec[1],
                    c = vec[2];

                if (dis[a] != max_int && dis[a] + c < dis[b])
                    dis[b] = dis[a] + c;
            }
        }

        for (vector<int> vec : edges)
        {
            int a = vec[0],
                b = vec[1],
                c = vec[2];

            if (dis[a] != max_int && dis[a] + c < dis[b])
            {
                cycle = true;
                break;
            }
        }

        if (cycle)
        {
            vector<int> tmp_dis;
            tmp_dis.push_back(-1);
            return tmp_dis;
        }

        return dis;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int N, m;
        cin >> N >> m;

        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends