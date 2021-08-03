//Problem Link:- https://www.interviewbit.com/old/problems/smallest-multiple-with-0-and-1/

#include<bits/stdc++.h>
using namespace std;

string multiple(int n) {
    if (n == 1){
        return "1";
    }
    vector<string> dp(n);
    dp[1] = "1";
    queue<int> pq;
    pq.push(1);
    while (!pq.empty()){
        int r = pq.front();
        pq.pop();
        if (r == 0){
            return dp[r];
        }
        for(int digit : {0,1}){
            int new_r = (r*10 + digit)%n;
            if (dp[new_r].empty()){
                pq.push(new_r);
                dp[new_r] = dp[r] + char(digit + '0');
            }
        }
    }
    return "-1";
}

