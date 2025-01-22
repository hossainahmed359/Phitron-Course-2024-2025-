#include <bits/stdc++.h>
using namespace std;

int main()
{

    // ========== MAX PRIORITY QUEUE ==========
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(20);

    cout << pq.top() << endl;

    pq.pop();
    pq.pop();

    cout << pq.top() << endl;

    // pq.size();
    // pq.empty();

    cout << endl;

    // ========== MIN PRIORITY QUEUE ==========
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(10);
    pq_min.push(5);
    pq_min.push(30);
    pq_min.push(20);

    cout << pq_min.top() << endl;

    pq_min.pop();
    pq_min.pop();

    cout << pq_min.top() << endl;

    // pq_min.size();
    // pq_min.empty();

    return 0;
}