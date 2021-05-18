//Problem Link:- https://www.interviewbit.com/problems/balanced-parantheses/

#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        if (s[i] == '('){
            cnt++;
        }
        else{
            cnt--;
            if (cnt < 0){
                return 0;
            }
        }
    }
    if (cnt != 0){
        return 0;
    }
    return 1;
}
