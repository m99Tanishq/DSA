#include <bits/stdc++.h>
using namespace std;
//https://www.techiedelight.com/find-minimum-number-deletions-convert-string-into-palindrome/
int minDeletions(string X, int n, string Y, int m){
     if(n >= m){
        return 0;
     }
     if(X[n] == Y[m]){
        return minDeletions(X,n+1,Y,m-1);
     }

     return  1 + min(minDeletions(X,n,Y,m-1) , minDeletions(X,n+1,Y,m));
}

void solve(){
     string X = "ACBCDBAA";
     int n = X.length();
     string Y = X;
 
    cout << "The minimum number of deletions required is " <<
        minDeletions(X, 0, Y, n-1);
}