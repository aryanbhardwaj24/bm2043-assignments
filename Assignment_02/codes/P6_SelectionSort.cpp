#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &v) {
    int n = v.size();

    for(int i=0;i<n-1;i++) {
        int mini_index = i+1;
        for(int j=i+2;j<n;j++) {
            if(v[j]<v[mini_index]) swap(j,mini_index);
        }

        if(v[i]>v[mini_index]) swap(v[i],v[mini_index]);
    }
}

int main () {
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    selection_sort(v);

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/