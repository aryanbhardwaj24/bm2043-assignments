#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
    private:
        stack<T> s1;
        stack<T> s2;
    public:
        void push(T data) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(data);

            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        T front() {
            return s1.top();
        }

        bool empty() {
            return s1.empty();
        }

        void pop() {
            s1.pop();
        }
};

int main () {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}

/*
Time Complexity:
    1] push: O(n)
    2] pop: O(1)
    3] front: O(1)
    4] empty: O(1)

Space Complexity: O(1)
*/