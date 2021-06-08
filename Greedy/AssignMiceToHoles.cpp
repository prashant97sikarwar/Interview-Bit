//Problem Link:- https://www.interviewbit.com/problems/assign-mice-to-holes/

#include<bits/stdc++.h>
using namespace std;

int mice(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size();
    int res = -1;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int i=0;i<n;i++){
        res = max(res, abs(nums1[i] - nums2[i]));
    }
    return res;
}
