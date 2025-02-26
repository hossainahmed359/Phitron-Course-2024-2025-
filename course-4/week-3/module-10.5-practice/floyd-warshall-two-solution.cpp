// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Floyd Warshall


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    void shortestDistance(vector<vector<int>> &mat)
    {
        int n = mat.size();

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int ik = mat[i][k],
                        kj = mat[k][j],
                        ij = mat[i][j];

                    if (ik == -1 || kj == -1)
                        continue;

                    if (ij == -1 || ik + kj < ij)
                        mat[i][j] = ik + kj;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"<< "\n";
    }
    return 0;
}
// } Driver Code Ends