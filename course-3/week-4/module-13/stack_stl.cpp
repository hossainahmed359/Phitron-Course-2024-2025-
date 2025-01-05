#include <bits/stdc++.h>
using namespace std;


/*
    st.push() -> O(1)
    st.pop() -> O(1)
    st.top() -> O(1)
    st.size() -> O(1)
    st.empty() -> O(1)
 */

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        st.push(v);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}