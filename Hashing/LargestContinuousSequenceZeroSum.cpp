//Problem Link:- https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

#include<bits/stdc++.h>
using namespace std;

vector<int> lszero(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int,int> ump;
    int sm = 0;
    int res = 0,l = 0,r = 0;
    ump[0] = -1;
    for(int i=0;i<n;i++){
        sm += nums[i];
        if (ump.find(sm) == ump.end()){
            ump[sm] = i;
        }
        else if (sm == 0){
            int lt = ump[sm];
            if (i+1 > res){
                l = lt;
                res = i+1;
                r = i;
            }
        }
        else if (ump.find(sm) != ump.end()){
            int lt = ump[sm];
            if (i-lt > res){
                l = lt;
                res = i-l;
                r = i;
            }
        }
    }
    vector<int> result;
    for(int i=l+1;i<=r;i++){
        result.push_back(nums[i]);
    }
    return result;
}
