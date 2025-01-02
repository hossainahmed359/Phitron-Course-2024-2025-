#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL for doubly linked list
    list<int> l = {5, 5, 3, 4, 5, 6, 7, 8, 5, 45, 77, 2, 2, 2};

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.remove(5);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.sort();

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.sort(greater<int>());

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    // THE LIST MUST BE SORTED !imporant
    l.unique();

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.reverse();

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}