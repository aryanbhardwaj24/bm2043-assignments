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

ListNode *reverse_ll(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool is_palindrome(ListNode *head) {
    if(!head || !head->next) return true;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    auto h2 = reverse_ll(slow->next);
    slow->next = NULL;

    slow = head;
    while(h2) {
        if(slow->val!=h2->val) return false;
        slow = slow->next;
        h2 = h2->next;
    }
    return true;
}

int main () {
    ListNode *head = make_ll();
    
    if(is_palindrome(head)) cout<<"Palindrome!"<<endl;
    else cout<<"Not a palindrome!"<<endl;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/