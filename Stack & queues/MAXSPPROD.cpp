//Problem Link:- https://www.interviewbit.com/problems/maxspprod/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int maxSpecialProduct(vector<int> &nums) {
    ll n = nums.size();
    long long mod = 1e9 + 7;
    stack<pair<ll,ll>> left, right;
    vector<ll> l(n),r(n);
    for(ll i=0;i<n;i++){
        ll x = 0;
        while (!left.empty() && left.top().first <= nums[i]){
            left.pop();
        }
        if (!left.empty()){
            x = left.top().second;
        }
        l[i] = x;
        left.push({nums[i],i});
    }
    for(ll i=n-1;i>=0;i--){
        ll x = 0;
        while (!right.empty() && right.top().first <= nums[i]){
            right.pop();
        }
        if (!right.empty()){
            x = right.top().second;
        }
        r[i] = x;
        right.push({nums[i],i});
    }
    long long ans = 0;
    for(ll i=0;i<n;i++){
        ans = max(ans,1LL*l[i]*r[i]);
    }
    return (ll)ans%mod;
    
}
