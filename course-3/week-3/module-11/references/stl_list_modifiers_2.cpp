#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL for doubly linked list
    list<int> l = {5, 5, 3, 4, 5, 6, 7, 8, 5, 45, 77};

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    auto idx = next(l.begin(), 3);

    l.erase(idx);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    auto begin = next(l.begin(), 2);
    auto end = next(l.begin(), 7);

    l.erase(begin, end);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    // WORKS AS SAME AS VECTOR
    replace(l.begin(), l.end(), 5, 100);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    auto it = find(l.begin(), l.end(), 45);

    if (it == l.end())
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Found";
    }

    return 0;
}