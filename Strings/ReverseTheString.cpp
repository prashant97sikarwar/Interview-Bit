//Problem Link:- https://www.interviewbit.com/problems/reverse-the-string/

#include<bits/stdc++.h>
using namespace std;

string solve(string str) {
    string ans="";
    for(int i=0;i<str.size();i++){
        if(str[i]==' ')continue;
        string temp="";
        while(i<str.size() && str[i]!=' ')
        {
            temp+=str[i];
            i++;
        }
        if(ans=="")
        ans+=temp;
        else
        ans=temp+" "+ans;
    }
    return ans;
 }
 