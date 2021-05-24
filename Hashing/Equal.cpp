//Problem Link:- https://www.interviewbit.com/problems/equal/

#include<bits/stdc++.h>
using namespace std;

bool valid(int f,int s,int t,int c){
    if (f < s && t < c && f < t && s != c && s != t){
        return true;
    }
    return false;
}
bool small(vector<int> ans, vector<int> temp){
    int i = 0;
    while (i < 4){
        if (ans[i] == temp[i]){
            i++;
        }
        else if (temp[i] < ans[i]){
            return true;
        }
        else{
            return false;
        }
    }
    return false;    
}

vector<int> equal(vector<int> &nums){
    int n = nums.size();
    unordered_map<int,pair<int,int>> ump;
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sm = nums[i] + nums[j];
            if (ump.find(sm) != ump.end()){
                int f = ump[sm].first;
                int s = ump[sm].second;
                int t = i;
                int c = j;
                if (valid(f,s,t,c)){
                    vector<int> temp = {f,s,t,c};
                    if (ans.size() == 0){
                        ans = temp;
                    }
                    else{
                        if (small(ans,temp)){
                            ans = temp;
                        }
                    }
                }
            }
            else{
                ump[sm] = {i,j};
            }
        }
    }
    return ans;
}
