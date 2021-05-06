//Problem Link;- https://www.interviewbit.com/problems/amazing-subarrays/

#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int res = 0;
    int n = s.length();
    set<char> mst = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I','O','U'};
    for(int i=0;i<s.length();i++){
        char temp = s[i];
        if (mst.find(temp) != mst.end()){
            res += (n-i);
            res %= 10003;
        }
    }
    return res%10003;
}
