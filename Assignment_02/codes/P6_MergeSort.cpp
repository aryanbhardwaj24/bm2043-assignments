#include <bits/stdc++.h>
using namespace std;

void merge(int s, int mid, int e, vector<int> &v) {
    vector<int> x;
    vector<int> y;

    for(int i=s;i<=mid;i++) x.push_back(v[i]);
    for(int i=mid+1;i<=e;i++) y.push_back(v[i]);

    int x_index = 0;
    int y_index = 0;

    int index = s;

    while(x_index<x.size() && y_index<y.size()) {
        if(x[x_index]<y[y_index]) v[index++] = x[x_index++];
        else v[index++] = y[y_index++];
    }

    while(x_index<x.size()) v[index++] = x[x_index++];
    while(y_index<y.size()) v[index++] = y[y_index++];
}

void merge_sort(int s, int e, vector<int> &v) {
    if(s>=e) return;

    int mid = s + (e-s)/2;

    merge_sort(s,mid,v);
    merge_sort(mid+1,e,v);

    merge(s,mid,e,v);
}

int main () {
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    merge_sort(0,n-1,v);

    return 0;
}

/*
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/