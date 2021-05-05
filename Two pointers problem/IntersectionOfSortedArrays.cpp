//Problem Link:- https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> result;
    int i = 0,j = 0,n = nums1.size(),m = nums2.size();
    while (i < n && j < m){
        if (nums1[i] == nums2[j]){
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return result;
}
