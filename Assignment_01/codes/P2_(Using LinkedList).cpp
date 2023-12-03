#include <bits/stdc++.h>
using namespace std;

class LinkedList;

class Node {
    private:
        int data;
        Node *next;
    public:
        Node () : data(0), next(NULL) {}
        Node (int data) : data(data), next(NULL) {}
        ~Node () {
            delete this->next;
        }

        friend class LinkedList;
        friend class Queue;
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        LinkedList () : head(NULL), tail(NULL) {}
        ~LinkedList () {
            this->tail = NULL;
            delete this->head;
        }

        void insertion (int data) {
            Node *temp = new Node (data);
            if(!head) head = tail = temp;
            else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void deletion (int data) {
            if(!head) return;
            if(head->data == data) {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
            else {
                Node *prev = NULL;
                Node *curr = head;

                while(curr && curr->data!=data) {
                    prev = curr;
                    curr = curr->next;
                }

                if(curr) {
                    Node *temp = curr->next;
                    prev->next = temp;
                    curr->next = NULL;
                    delete curr;
                }
            }
        }

        bool search (int data) {
            Node *curr = head;
            while(curr && curr->data!=data) curr = curr->next;
            return curr;
        }

        void display () {
            Node *curr = head;
            while(curr) {
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<"NULL"<<endl;
        }

        int Head () {
            return head->data;
        }

        friend class Queue;
};

class Queue {
    private:
        LinkedList l;
        int size;
    public:
        Queue() : size(0) {}

        int front () {
            return l.Head();
        }

        void Push (int data) {
            l.insertion(data);
            this->size++;
        }

        bool isEmpty() {
            return this->size==0;
        }

        void pop () {
            Node *temp = l.head;
            l.head = l.head->next;
            temp->next = NULL;
            delete temp;
            this->size--;
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

    while(!q.isEmpty()) {
        cout<<"Front: "<<q.front()<<" and Size: "<<q.Size()<<endl;
        q.pop();
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