//Problem Link:- https://www.interviewbit.com/problems/excel-column-number/

#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string s) {
    int n = s.length();
    if (n == 1){
        return s[0]-'A'+1;
    }
    int res = 0;
    for(const auto &c : s){
        res *= 26;
        res += c-'A'+1;
    }
    return res;
}

