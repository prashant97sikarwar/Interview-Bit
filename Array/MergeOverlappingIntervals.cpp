//Problem Link:- https://www.interviewbit.com/problems/merge-overlapping-intervals/

#include<bits/stdc++.h>
using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

 
 bool cmp(Interval one,Interval two){
    if (one.start < two.start){
        return true;
    }
    else if (one.start == two.start){
        return one.end < two.end;
    }
    return false;
 }
 
vector<Interval> merge(vector<Interval> &nums) {
    sort(nums.begin(),nums.end(),cmp);
    int st = nums[0].start;
    int end = nums[0].end;
    vector<Interval> result;
    for(int i=1;i<nums.size();i++){
        int x = nums[i].start;
        int y = nums[i].end;
        if (end >= x){
            end = max(end,y);
        }
        else{
            result.push_back(Interval(st,end));
            st = nums[i].start;
            end = nums[i].end;
        }
    }
    result.push_back(Interval(st,end));
    return result;
}
