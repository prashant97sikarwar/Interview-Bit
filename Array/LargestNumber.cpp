//Problem Link:- https://www.interviewbit.com/problems/largest-number/

#include<bits/stdc++.h>
using namespace std;

bool cmp(string s1,string s2){
    return s1 + s2 > s2 + s1;
}

string largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> s;
    for(int i=0;i<n;i++){
        s.push_back(to_string(A[i]));
    }
    sort(s.begin(),s.end(),cmp);
    cout << s[0]<< endl;
    if (s[0] == to_string(0))
        return "0";
    string res = "";
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            res += s[i][j];
        }
    }
    return res;
    
}
