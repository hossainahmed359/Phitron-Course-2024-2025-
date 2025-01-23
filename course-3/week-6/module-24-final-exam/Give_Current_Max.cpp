// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/get-current-max
// Give Current Max

#include <bits/stdc++.h>
using namespace std;

class Student
{

public:
    string name;
    int roll, marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    };
};

class Comp
{
public:
    bool operator()(Student *a, Student *b)
    {
        if (a->marks == b->marks)
            return a->roll > b->roll;

        return a->marks < b->marks;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student *, vector<Student *>, Comp> pq_max;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        pq_max.push(new Student(name, roll, marks));
    }

    // while (!pq_max.empty())
    // {
    //     Student *topStudent = pq_max.top();
    //     cout << topStudent->name << " " << topStudent->roll << " " << topStudent->marks << endl;
    //     pq_max.pop();
    // }

    int q; /* Number of queries */
    cin >> q;
    while (q--)
    {

        /*
            0 -> input int x &  print current max,
            1 -> print current max,
            2 -> delete current max & print current max after deletion
        */
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            pq_max.push(new Student(name, roll, marks));

            Student *topStudent = pq_max.top();
            cout << topStudent->name << " " << topStudent->roll << " " << topStudent->marks << endl;
        }
        else if (cmd == 1)
        {
            if (pq_max.empty())
            {
                cout << "Empty" << endl;
                continue;
            }

            Student *topStudent = pq_max.top();
            cout << topStudent->name << " " << topStudent->roll << " " << topStudent->marks << endl;
        }
        else if (cmd == 2)
        {

            if (!pq_max.empty())
            {
                pq_max.pop();
            }

            if (pq_max.empty())
            {
                cout << "Empty" << endl;
                continue;
            }

            Student *topStudent = pq_max.top();
            cout << topStudent->name << " " << topStudent->roll << " " << topStudent->marks << endl;
        }
    }

    return 0;
}
