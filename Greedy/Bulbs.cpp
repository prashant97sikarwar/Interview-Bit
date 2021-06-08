//Problem Link:- https://www.interviewbit.com/problems/interview-questions/

#include<bits/stdc++.h>
using namespace std;

int bulbs(vector<int> &nums){
    int n = nums.size();
    int k = 0, res = 0;
    for(int i=0;i<n;i++){
        if (k == nums[i]){
            res++;
            if (k == 1){
                k = 0;
            }
            else{
                k = 1;
            }
        }
    }
    return res;
}
