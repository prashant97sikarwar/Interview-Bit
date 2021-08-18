//Problem Link:- https://www.interviewbit.com/old/problems/gas-station/

#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    const int n = gas.size();
    vector<int> nums(n,0);
    int fuel = 0;
    int idx = -1;
    bool flag = false;
    for(int i=0;i<n;i++){
        if (fuel + gas[i] < cost[i]){
            nums[i] = 0;
            fuel = 0;
            flag = false;
            idx = -1;
        }
        else{
            if (flag == false){
                idx = i;
                flag = true;
            }
            fuel += gas[i] - cost[i];
            nums[i] = 1;
        }
    }
    for(int i=0;i<n && i < idx;i++){
        if (fuel + gas[i] < cost[i]){
            nums[i] = 0;
            fuel = 0;
            flag = false;
            idx = -1;
        }
        else{
            if (flag == false){
                idx = i;
                flag = true;
            }
            fuel += gas[i] - cost[i];
            nums[i] = 1;
        }
    }
    return idx;
}
