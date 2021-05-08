//Problem Link:- https://www.interviewbit.com/problems/city-tour/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long power(int base, int exp){
    if(exp==0) return 1;
    long long ans = ((power(base, exp/2)%mod)*(power(base, exp/2)%mod))%mod;
    if(exp%2 == 0) return ans;
    else return (ans*base)%mod;
}

int solve(int numCities, vector<int> &visited) {
    sort(visited.begin(), visited.end());
    vector<int> interval;
    interval.push_back(visited[0]-1);
    for(int i=1; i<visited.size(); i++) interval.push_back(visited[i]-visited[i-1]-1);
    interval.push_back(numCities-visited.back());
    
    int remaining=numCities-visited.size();
    long long ans=1;
    for(int i=2; i<=remaining; i++){
        ans *= i;
        ans %= mod;
    }
    int n=0;
    for(int i=1; i<interval.size()-1; i++) if(interval[i]) n += (interval[i]-1);
    for(int i=0; i<n; i++){
        ans *= 2;
        ans %= mod;
    }
    for(auto x:interval){
        for(int i=2; i<=x; i++){
            ans *= power(i, mod-2);
            ans %= mod;
        }
    }
    return ans;
}