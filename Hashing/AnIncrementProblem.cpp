//Problem Link:- https://www.interviewbit.com/problems/an-increment-problem/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a) {
    unordered_map<int,int> m;
    for(int i=0; i<a.size(); i++)
    {
        if(m.count(a[i]))
        {
            a[m[a[i]]]++;
            m[a[i]+1] = m[a[i]];
        }
        m[a[i]] = i;
    }
    return a;
}