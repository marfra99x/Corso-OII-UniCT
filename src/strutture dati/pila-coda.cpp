#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    queue<char> q;
    priority_queue<char, vector<char>, greater<char>> pq_asc;
    priority_queue<int> pq;
    stack<double> s;

    // inserimento pila
    s.push(1.5);
    s.push(4.4);
    s.push(500.95);

    // inserimento coda
    q.push('a');
    q.push('g');
    q.push('o');

    // inserimento coda di priorità
    pq.push(1);
    pq.push(5);

    // pop dalla pila
    cout << s.top() << ' ';
    s.pop();
    cout << s.top() << ' ';

    while (!s.empty())
        s.pop();

    // pop dalla coda
    cout << q.front() << ' ';
    cout << q.back() << ' ';
    q.pop();
    cout << q.front() << ' ';
    cout << q.back() << ' ';

    // elemento principale della priority queue
    cout << pq.top() << ' ';

    return 0;
}