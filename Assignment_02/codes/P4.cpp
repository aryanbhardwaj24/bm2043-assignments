#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode () : val(0), next(NULL) {}
        ListNode (int val) : val(val), next(NULL) {}

        ~ListNode () {
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
            tail = tail->next;
        }
    }
    return head;
}

ListNode *middle_node(ListNode *head) {
    if(!head->next) return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main () {
    ListNode *head = make_ll();

    if(!head) {
        cout<<"Middle element of linked list: -1"<<endl;
    }

    else {
        ListNode *node = middle_node(head);
        cout<<"Middle element of linked list: "<<node->val<<endl;
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/