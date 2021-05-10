//Problem Link:- https://www.interviewbit.com/problems/next-similar-number/

#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
    int n = s.length();
    string result = "-1";
    if (n == 1){
        return result;
    }
    int i = n-2;
    while (i >= 0 && s[i] >= s[i+1]){
        i--;
    }
    if (i < 0){
        return result;
    }
    int j = n-1;
    while (j > 0 && s[j] <= s[i]){
        j--;
    }
    swap(s[i],s[j]);
    sort(s.begin()+i+1,s.end());
    return s;
}
