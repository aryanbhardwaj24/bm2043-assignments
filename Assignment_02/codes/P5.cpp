#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode *prev;

        ListNode () : val(0), next(NULL), prev(NULL) {}
        ListNode (int val) : val(val), next(NULL), prev(NULL) {}

        ~ListNode () {
            this->prev = NULL;
            delete this->next;
        }
};

ListNode *make_ll() {
    int n;
    cin>>n;

    ListNode *head = NULL;
    ListNode *tail = NULL;

    while(n--) {
        int input;
        cin>>input;

        ListNode *temp = new ListNode(input);
        if(!head) head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }
    return head;
}

ListNode *reverse_ll(ListNode *head) {
    if(!head || !head->next) return head;

    ListNode *pr = NULL;
    ListNode *curr = head;

    while(curr) {
        ListNode *temp = curr->next;
        if(temp) temp->prev = NULL;
        curr->next = pr;
        if(pr) pr->prev = curr;
        pr = curr;
        curr = temp;
    }
    return pr;
}

void print_ll(ListNode *head) {
    ListNode *curr = head;
    while(curr) {
        cout<<curr->val<<" ⇌ ";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int main () {
    ListNode *head = make_ll();
    print_ll(reverse_ll(head));
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/