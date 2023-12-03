#include <bits/stdc++.h>
using namespace std;

string helper(string &s) {
    int n = s.size();

    stack<char> st;

    for(int i=0;i<n;i++) {
        if(st.empty() || st.top()!=s[i]) st.push(s[i]);
        else {
            int j=i+1;
            while(j<n && s[j]==s[i]) j++;
            st.pop();
            i = j-1;
        }
    }

    string ans;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main () {
    string s;
    cin>>s;

    cout<<helper(s)<<endl;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/