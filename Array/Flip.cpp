//Problem Link:- https://www.interviewbit.com/problems/flip/

#include<bits/stdc++.h>
using namespace std;

vector<int> flip(string s) {
    int n = s.length();
    int cur_sum = 0;
    int res = 0;
    int t = 1;
    int start = 0;
    int end = 0;
    for(int i=1;i<=n;i++){
        int num;
        if (s[i-1] == '0'){
            num = 1;
        }
        else{
            num = -1;
        }
        cur_sum += num;
        if (cur_sum > res){
            res = cur_sum;
            start = t;
            end = i;
        }
        if (cur_sum < 0){
            cur_sum = 0;
            t = i+1;
        }
    }
    if (start == end && end == 0){
        return {};
    }
    else{
        return {start,end};
    }
}
