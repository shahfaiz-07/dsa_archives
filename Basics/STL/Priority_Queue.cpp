#include<bits/stdc++.h>
using namespace std;

int main(void) {
    priority_queue<int> pq; // MAX HEAP
    pq.push(5); // {5} - O(log(n))
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2} - Largest Element at top;

    pq.pop(); // O(log(n))
    // Other functions are pop, top, size, empty

    // PRIORITY QUEUE TO STORE THE MINIMUM ELEMENT AT THE TOP
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.push(10);


    cout << pq2.top() << endl; // 2
    return 0;
}