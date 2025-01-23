// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/pairs-17
// Pairs

#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int id;
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

bool comp(Person *a, Person *b)
{

    string nameA = a->name;
    int idA = a->id;

    string nameB = b->name;
    int idB = b->id;

    if (nameA.compare(nameB) == 0)
        return idA > idB;

    return nameA.compare(nameB) < 0;
}

int main()
{

    vector<Person *> arr;

    int n;
    cin >> n;

    while (n--)
    {
        string name;
        int id;
        cin >> name >> id;
        arr.push_back(new Person(name, id));
    }

    sort(arr.begin(), arr.end(), comp);

    for (auto curr : arr)
    {
        cout << curr->name << " " << curr->id << endl;
    }

    return 0;
}
