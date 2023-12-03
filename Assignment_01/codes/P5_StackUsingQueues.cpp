#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
    private:
        queue<T> q1;
        queue<T> q2;
    public:
        void push(T data) {
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(data);

            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }

        T top() {
            return q1.front();
        }

        bool empty() {
            return q1.empty();
        }

        void pop() {
            q1.pop();
        }
};

int main () {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}

/*
Time Complexity:
    1] push: O(n)
    2] pop: O(1)
    3] top: O(1)
    4] empty: O(1)

Space Complexity: O(1)
*/