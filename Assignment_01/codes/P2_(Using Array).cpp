#include <bits/stdc++.h>
using namespace std;

class Queue {
    private:
        int *container;
        int size;
        int capacity;
        int head;
        int tail;
    public:
        Queue () {
            this->size = 0;
            this->capacity = 5;
            this->head = -1;
            this->tail = -1;
            this->container = new int [this->capacity];
        }

        int front () {
            return container[head];
        }

        void Push (int data) {
            if(head==-1) {
                this->head = this->tail = 0;
                this->container[this->tail] = data;
                this->tail++;
                this->size++;
                return;
            }

            if(size==capacity) {
                int new_capacity = 2*this->capacity;
                int *temp = this->container;
                this->container = new int [new_capacity];

                this->container[0] = temp[head];
                this->head = (this->head+1)%this->capacity;

                int index = 1;
                while(this->head!=this->tail) {
                    this->container[index++] = temp[head];
                    this->head = (this->head+1)%this->capacity;
                }

                this->head = 0;
                this->tail = this->capacity;
                this->capacity = new_capacity;
                delete []temp;
            }

            this->container[tail] = data;
            this->size++;
            this->tail = (this->tail+1)%this->capacity;
        }

        void Pop () {
            this->head = (this->head+1)%this->capacity;
            this->size--;
        }

        bool isEmpty () {
            return this->size==0;
        }

        int Size () {
            return this->size;
        }
};

int main () {
    Queue q;

    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    q.Push(6);

    while(!q.isEmpty()) {
        cout<<"Front: "<<q.front()<<" and Size: "<<q.Size()<<endl;
        q.Pop();
    }

    return 0;
}

/*
Time Complexity:
    Front: O(1)
    Push: O(1)
    isEmpty: O(1)
    Pop: O(1)
    Size: O(1)

Space Complexity: O(1)
*/