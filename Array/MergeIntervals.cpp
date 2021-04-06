//Problem Link:- https://www.interviewbit.com/problems/merge-intervals/

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
    if (one.start == two.start){
        return one.end < two.end;
    }
    return false;
 }
 
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int new_st = newInterval.start;
    int new_end = newInterval.end;
    vector<Interval> result;
    int fr = new_st;
    int er = new_end;
    for(auto cur : intervals){
        int st = cur.start;
        int end = cur.end;
        if (end < new_st){
            result.push_back(cur);
        }
        else if (st > new_end){
            result.push_back(cur);
        }
        else if (st >= new_st && end <= new_end){
            continue;
        }
        else if(end <= new_end){
            fr = min(st,fr);
        }
        else if (st >= new_st){
            er = max(er,end);
        }
    }
    result.push_back(Interval(fr,er));
    sort(result.begin(),result.end(),cmp);
    return result;
}
