#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int id;
    int marks;

    Student(string name, int id, int marks)
    {
        this->name = name;
        this->id = id;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student const &l, Student const &r)
    {
        return l.marks > r.marks; // Sort by marks in ascending order
    }
};

int main()
{
    // Priority queue with custom comparator
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n; // Initialize `n` with the number of students
    while (n--)
    {
        string name;
        int id, marks;
        cin >> name >> id >> marks;
        Student obj(name, id, marks);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        Student topStudent = pq.top(); // Retrieve the top element
        cout << topStudent.name << " " << topStudent.id << " " << topStudent.marks << endl;
        pq.pop();
    }

    return 0;
}

/*

3
Alex 4 99
Frank 1 55
Alison 2  100

 */