//Problem Link:- https://www.interviewbit.com/problems/hotel-bookings-possible/

#include<bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int res = 1;
    int cnt = 1;
    int i=1,j=0;
    while (i < arrive.size() && j < depart.size()){
        if (arrive[i] < depart[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        res = max(res,cnt);
    }
    return (res <= K) ? true : false;
}
