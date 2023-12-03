#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums) {
    int n = nums.size();

    stack<int> s;
    s.push(nums.back());
    nums[n-1] = -1;

    for(int i=n-2;i>=0;i--) {
        int val = nums[i];

        while(!s.empty() && s.top()<=val) s.pop();

        if(s.empty()) nums[i] = -1;
        else nums[i] = s.top();

        s.push(val);
    }
}

void print(vector<int> &nums) {
    for(const auto &i:nums) cout<<i<<" ";
    cout<<endl;
}

int main () {
    int n;
    cin>>n;

    vector<int> input(n);
    for(auto &i:input) cin>>i;

    helper(input);
    print(input);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/