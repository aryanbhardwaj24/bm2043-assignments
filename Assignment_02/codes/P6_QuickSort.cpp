#include <bits/stdc++.h>
using namespace std;

void quick_sort(int s, int e, vector<int> &v) {
    if(s>=e) return;

    int count_smaller = 0;
    for(int i=s;i<e;i++) if(v[i]<v[e]) count_smaller++;

    int pivot_index = s+count_smaller;
    swap(v[e],v[pivot_index]);

    int i=s;
    int j=e;

    while(i<pivot_index && j>pivot_index) {
        if(v[i]>=v[pivot_index] && v[j]<v[pivot_index]) swap(v[i++],v[j--]);
        else if(v[i]>=v[pivot_index] && v[j]>=v[pivot_index]) j--;
        else if(v[i]<v[pivot_index] && v[j]<v[pivot_index]) i++;
        else {
            i++;
            j--;
        }
    }

    quick_sort(s,pivot_index-1,v);
    quick_sort(pivot_index+1,e,v);
}

int main () {
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    quick_sort(0,n-1,v);

    return 0;
}

/*
Time Complexity:
    Average Case: O(nlogn)
    Worst Case: O(n^2)

Space Complexity:
    If we don't consider recursive stack space: O(1)
    If we consider recursive stack space:
        Average case: O(log n)
        Worst case: O(n)
*/