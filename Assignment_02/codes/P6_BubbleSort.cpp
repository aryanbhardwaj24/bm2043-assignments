#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v) {
    int n = v.size();

    for(int i=0;i<n-1;i++) {
        bool check = true;
        for(int j=0;j<n-1;j++) {
            if(v[j]>v[j+1]) {
                swap(v[j],v[j+1]);
                check = false;
            }
        }
        if(check) break;
    }
}

int main () {
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    bubble_sort(v);
    
    return 0;
}

/*
Time Complexity:
    1] For unsorted array: O(n^2)
    2] For sorted array: O(n)

Space Complexity: O(1)
*/