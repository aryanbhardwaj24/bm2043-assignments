#include <bits/stdc++.h>
using namespace std;

bool valid_string(string &s) {
    int n = s.size();

    stack<char> st;
    for(int i=0;i<n;i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else if(s[i]==')') {
            if(st.empty() || st.top()!='(') return false;
            else st.pop();
        }
        else if(s[i]=='}') {
            if(st.empty() || st.top()!='{') return false;
            else st.pop();
        }
        else if(s[i]==']') {
            if(st.empty() || st.top()!='[') return false;
            else st.pop();
        }
        else return false;
    }
    return true;
}

int main () {
    string s;
    getline(cin>>ws,s);

    if(valid_string(s)) cout<<"Beautiful string."<<endl;
    else cout<<"Non-beautiful string."<<endl;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/