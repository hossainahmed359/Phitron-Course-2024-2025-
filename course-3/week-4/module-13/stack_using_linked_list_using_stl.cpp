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
    list<int> l;

    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_back();
    }

    int top()
    {
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
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