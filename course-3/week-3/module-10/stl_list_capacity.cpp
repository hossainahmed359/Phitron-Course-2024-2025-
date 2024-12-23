#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL for doubly linked list
    list<int> l(10, 3);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.clear();

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.resize(5, 25);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    return 0;
}