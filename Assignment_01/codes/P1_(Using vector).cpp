#include <bits/stdc++.h>
using namespace std;

class Stack {
    private:
        vector<int> container;
    public:
        int Top () {
            return container.back();
        }

        void Push (int data) {
            container.push_back(data);
        }

        int Peek () {
            return container.back();
        }

        bool isEmpty () {
            return container.empty();
        }

        void pop () {
            container.pop_back();
        }

        int size () {
            return container.size();
        }
};

int main () {
    Stack s;

    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    while(!s.isEmpty()) {
        cout<<"Top: "<<s.Top()<<" and Size: "<<s.size()<<endl;
        s.pop();
    }

    return 0;
}

/*
Time Complexity:
    Top: O(1)
    Push: O(1)
    Peek: O(1)
    isEmpty: O(1)
    pop: O(1)
    size: O(1)

Space Complexity: O(1)
*/