//Problem Link:- https://www.interviewbit.com/problems/balance-array/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    int n = nums.size();
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 0;
    }
    vector<int>lo(n,0);
    vector<int>le(n,0);
    vector<int>re(n,0);
    vector<int>ro(n,0);
    lo[1] = nums[1];
    le[0] = nums[0];
    le[1] = nums[0];
    for(int i=2;i<n;i++){
        if (i%2 == 0){
            le[i] = nums[i] + le[i-2];
            lo[i] = lo[i-1];
        }
        else{
            lo[i] = nums[i] + lo[i-2];
            le[i] = le[i-1];
        }
    }
    if ((n-1) % 2 == 0){
        re[n-1] = nums[n-1];
        ro[n-2] = nums[n-2];
        re[n-2] = re[n-1];
    }
    else{
        ro[n-1] = nums[n-1];
        re[n-2] = nums[n-2];
        ro[n-2] = ro[n-1];
    }
    for(int i=n-3;i>=0;i--){
        if (i%2 == 0){
            re[i] = nums[i] + re[i+2];
            ro[i] = ro[i+1];
        }
        else{
            ro[i] = nums[i] + ro[i+2];
            re[i] = re[i+1];
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if (i == 0){
            if (ro[i+1] == re[i+1]){
                cnt++;
            }
        }
        else if (i == n-1){
            if (lo[i-1] == le[i-1]){
                cnt++;
            }
        }
        else{
            int odd = lo[i-1] + re[i+1];
            int even = le[i-1] + ro[i+1];
            if (odd == even){
                cnt++;
            }
        }
    }
    return cnt;
}
