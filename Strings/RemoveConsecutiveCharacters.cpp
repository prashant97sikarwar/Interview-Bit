//Problem link:- https://www.interviewbit.com/problems/remove-consecutive-characters/

#include<bits/stdc++.h>
using namespace std;

string solve(string s, int k) {
    if (k == 1)
        return "";
    string output = "";
    int i = 0;
    int n = s.length();
    while (i < n){
        string temp = "";
        int j = i;
        while (j < n && s[j] == s[i]){
            temp += s[j];
            j++;
        }
        if (temp.size() != k){
            output += temp;
        }
        i = j;
    }
    return output;
}
