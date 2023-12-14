#include <bits/stdc++.h>
using namespace std;

class LinkedList;

class ListNode {
    private:
        int data;
        ListNode *next;
    public:
        ListNode () : data(0), next(NULL) {}
        ListNode (int data) : data(data), next(NULL) {}
        ~ListNode () {
            delete this->next;
        }

        friend class LinkedList;
};

class LinkedList {
    private:
        ListNode *head;
        ListNode *tail;
    public:
        LinkedList () : head(NULL), tail(NULL) {}
        ~LinkedList () {
            this->tail = NULL;
            delete this->head;
        }

        void insertion (int data) {
            ListNode *temp = new ListNode (data);
            if(!head) head = tail = temp;
            else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void deletion (int data) {
            if(!head) return;
            if(head->data == data) {
                ListNode *temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
            else {
                ListNode *prev = NULL;
                ListNode *curr = head;

                while(curr && curr->data!=data) {
                    prev = curr;
                    curr = curr->next;
                }

                if(curr) {
                    ListNode *temp = curr->next;
                    prev->next = temp;
                    curr->next = NULL;
                    delete curr;
                }
            }
        }

        bool search (int data) {
            ListNode *curr = head;
            while(curr && curr->data!=data) curr = curr->next;
            return curr;
        }

        void display () {
            ListNode *curr = head;
            while(curr) {
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<"NULL"<<endl;
        }

        int Head () {
            return head->data;
        }
};

int main () {
    LinkedList l;

    l.insertion(1);
    l.insertion(2);
    l.insertion(3);
    l.insertion(4);
    l.insertion(5);

    l.display ();

    l.deletion(5);

    l.display ();

    cout<<l.search(1)<<endl;
    cout<<l.search(3)<<endl;
    cout<<l.search(5)<<endl;

    cout<<l.Head()<<endl;
    l.deletion(1);
    cout<<l.Head()<<endl;

    return 0;
}

/*
Time Complexity: 
    Insertion: O(1)
    Deletion: O(n)
    Search: O(n)
    Display: O(n)
    Head: O(1)

Space Complexity: O(1)
*/