#include <bits/stdc++.h>
using namespace std;

class LinkedList;

class Node {
    private:
        int data;
        Node *next;
        Node *prev;
    public:
        Node () : data(0), next(NULL), prev(NULL) {}
        Node (int data) : data(data), next(NULL), prev(NULL) {}
        ~Node () {
            this->prev = NULL;
            delete this->next;
        }

        friend class LinkedList;
        friend class Stack;
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
                temp->prev = tail;
                tail = tail->next;
            }
        }

        void deletion (int data) {
            if(!head) return;
            if(head->data == data) {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                head->prev = NULL;
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
                    if(temp) temp->prev = prev;
                    curr->prev = NULL;
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
                cout<<curr->data<<" <-> ";
                curr = curr->next;
            }
            cout<<"NULL"<<endl;
        }

        int Head () {
            return head->data;
        }

        int Tail () {
            return tail->data;
        }

        friend class Stack;
};

class Stack {
    private:
        LinkedList l;
        int size;
    public:
        Stack () : size(0) {}

        int Top () {
            return l.Tail();
        }

        void Push (int data) {
            l.insertion(data);
            this->size++;
        }

        int Peek () {
            return l.Tail();
        }

        bool isEmpty () {
            return this->size==0;
        }

        void pop () {
            if(this->size==1) {
                delete l.tail;
                l.head = l.tail = NULL;
            }
            else {
                Node *temp = l.tail;
                l.tail = l.tail->prev;
                temp->prev = NULL;
                l.tail->next = NULL;
                delete temp;
            }
            this->size--;
        }

        int Size () {
            return this->size;
        }
};

int main () {
    Stack s;

    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    while(!s.isEmpty()) {
        cout<<"Top: "<<s.Top()<<" and Size: "<<s.Size()<<endl;
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