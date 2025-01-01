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

    l.push_back(444);
    l.push_front(244);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    l.pop_back();
    l.pop_front();

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    cout << endl;

    cout << *next(l.begin(), 3) << endl;

    auto idx = next(l.begin(), 3);

    l.insert(idx, 100);

    cout << "Size: " << l.size() << ", Is Empty " << l.empty() << " -> ";

    for (int val : l)
    {
        cout << val << " ";
    }

    return 0;
}