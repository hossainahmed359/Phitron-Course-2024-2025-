#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL SET || BINARY SEARCH TREE BEHIND THE SCENE
    set<int> s;
    int n;
    while (n--)
    {
        int val;
        cin >> val;
        s.insert(val); /* longN */
    }

    for (auto it = s.begin(); it != s.end(); it++) /* NlongN */
    {
        cout << *it << endl;
    }

    // s.count(5); To check whether value exists or not 1, 0  NlongN 
    // cout << s.count(15) << endl;

    return 0;
}
