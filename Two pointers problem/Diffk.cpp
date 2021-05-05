//Problem Link:- https://www.interviewbit.com/problems/diffk/

#include<bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &nums, int k) {
    int n = nums.size();
    int i=0,j=1;
    while(j < n){
        int sm = nums[j]-nums[i];
        if (j-i > 1){
            if (sm == k){
                return 1;
            }
            else if (sm < k){
                j++;
            }
            else if(sm > k){
                i++;
            }
        }
        else if (j-i == 1){
            if (sm == k){
                return 1;
            }
            else if (sm > k){
                j++;
                i++;
            }
            else if (sm < k){
                j++;
            }
        }
    }
    return 0;
}
