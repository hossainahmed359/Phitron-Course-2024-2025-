#include <bits/stdc++.h>
using namespace std;

/*
    st.push() -> O(1)
    st.pop() -> O(1)
    st.top() -> O(1)
    st.size() -> O(1)
    st.empty() -> O(1)
 */

class Stack
{
public:
    vector<int> v;

    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
    }
};

int main()
{
    int n;
    cin >> n;

    Stack st;
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