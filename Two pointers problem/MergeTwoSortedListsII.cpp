//problem Link:- https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, vector<int> &nums2) {
    int i = nums1.size()-1, j=nums2.size()-1;
    int pos = nums1.size() + nums2.size() - 1;
    nums1.resize(nums1.size() + nums2.size());
    while (j >= 0){
        if (i >= 0 && nums1[i] > nums2[j]){
            nums1[pos--] = nums1[i--];
        }
        else{
            nums1[pos--] = nums2[j--];
        }
    }
}
