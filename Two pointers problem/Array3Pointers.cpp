//Problem Link:- https://www.interviewbit.com/problems/array-3-pointers/

#include<bits/stdc++.h>
using namespace std;

int minimize(const vector<int> &nums1, const vector<int> &nums2, const vector<int> &nums3){
    int i = 0,j = 0,k = 0;
    int p = nums1.size(), q = nums2.size(), r = nums3.size();
    int xi = 0,yi = 0,zi = 0;
    int diff = INT_MAX;
    while (i < p && j < q && k < r){
        int mn = min(nums1[i],min(nums2[j],nums3[k]));
        int mx = max(nums1[i],max(nums2[j],nums3[k]));
        if (mx - mn < diff){
            diff = mx - mn;
            xi = i;
            yi = j;
            zi = k;
        }
        if (diff == 0){
            break;
        }
        if (nums1[i] == mn){
            i++;
        }
        else if (nums2[j] == mn){
            j++;
        }
        else if (nums3[k] == mn){
            k++;
        }
    }
    int ans = max(abs(nums1[xi] - nums2[yi]), abs(nums2[yi] - nums3[zi]));
    ans = max(ans,abs(nums3[zi] - nums1[xi]));
    return ans;

}
