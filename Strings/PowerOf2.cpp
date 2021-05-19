//Problem Link:- https://www.interviewbit.com/problems/power-of-2/

#include<bits/stdc++.h>
using namespace std;

void removeFrontZeros(string &s) {
    int i = 0;
    int n = s.length();
    while (i < n && s[i] == '0') {
    i++;
    }
    
    s =  s.substr(i, n - i);
}

int Spower(string s) {
    removeFrontZeros(s);
    string dividend = s;
    string quotient = "";
    int rem = 0;
    
    int n = 0;
    int i = 0;
    int base = 0;
    while (1) {
    quotient = "";
    n = dividend.length();
    i = 0;
    rem = 0;
    while (i < n) {
      base = (rem * 10 + (dividend[i] - '0')) / 2;
      quotient.push_back(base + '0');
      rem = (rem * 10 + (dividend[i] - '0')) % 2;
      i++;
    }
    if(rem == 0 && quotient.length() == 1 && quotient[0] == '1' ) {
      return true;
    } else if (rem == 1) {
      return false;
    }
    removeFrontZeros(quotient);
    dividend = quotient;
    }
}