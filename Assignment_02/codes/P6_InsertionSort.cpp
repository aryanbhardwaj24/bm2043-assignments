#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v) {
    int n = v.size();

    for(int i=1;i<n;i++) {
        int j=i;
        while(j>0 && v[j]<v[j-1]) swap(v[j--],v[j]);
    }
}

int main () {
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    insertion_sort(v);

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/