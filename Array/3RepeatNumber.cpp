//Problem Link:- https://www.interviewbit.com/problems/n3-repeat-number/

#include<bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &nums) {
    int n = nums.size();
    int c1 = 0;
    int c2 = 0;
    int n1 = 0;
    int n2 = 0;
    int ans = -1;
    for(int i=0;i<n;i++){
        if (nums[i] == n1){
            c1++;
        }
        else if (nums[i] == n2){
            c2++;
        }
        else if (c1 == 0){
            n1 = nums[i];
            c1++;
        }
        else if (c2 == 0){
            n2 = nums[i];
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for(int num : nums){
        if (n1 == num){
            c1++;
        }
        else if (n2 == num){
            c2++;
        }
    }
    if (c1 > n / 3){
        ans = n1;
    }
    if (c2 > n / 3){
        ans = n2;
    }
    return ans;
}