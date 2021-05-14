//Problem Link:- https://www.interviewbit.com/problems/convert-to-palindrome/

#include<bits/stdc++.h>
using namespace std;

bool helper(string &s,int l,int r,int cnt){
    if (cnt > 1){
        return false;
    }
    if (l >= r ){
        return true;
    }
    if (s[l] == s[r]){
        return helper(s,l+1,r-1,cnt);
    }
    else{
        return helper(s,l+1,r,cnt+1) || helper(s,l,r-1,cnt+1);
    }
}

int solve(string s) {
    return helper(s,0,s.length()-1,0);
}
