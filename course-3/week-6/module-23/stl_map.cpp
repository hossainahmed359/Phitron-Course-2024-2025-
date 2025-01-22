#include <bits/stdc++.h>
using namespace std;

int main()
{

    // STL MAP
    map<string, int> mp;

    mp["foo"] = 120;
    mp["boo"] = 320;
    mp["bar"] = 620;

    // mp["kasper"] = 1111;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        string mpKey = it->first;
        int mapVal = it->second;

        cout << mpKey << " " << mapVal << endl;
    }

    if (mp.count("kasper"))
    {
        cout << "kasper exist" << endl;
    }
    else
    {
        cout << "kasper does not exist" << endl;
    }

    return 0;
}
