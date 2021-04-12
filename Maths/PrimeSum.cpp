//Problem Link:- https://www.interviewbit.com/problems/prime-sum/

#include<bits/stdc++.h>
using namespace std;

vector<int> primesum(int n) {
    vector<bool> arr(n+1,false);
    int p = 2;
    arr[0] = true;
    arr[1] = true;
    while (p*p <= n){
        if (arr[p] == false){
            for(int i=p*p;i<=n;i+=p){
                arr[i] = true;
            }
        }
        p+=1;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if (arr[i] == false && arr[n-i] == false){
            ans.push_back(i);
            ans.push_back(n-i);
            break;
        }
    }
    return ans;
}
