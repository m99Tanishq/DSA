#include <bits/stdc++.h>
using namespace std;

bool isInterleaving(string X, string Y, string S){
    if (!X.length() and !Y.length() and !!S.length()){
        return true;
    }
    if(!S.length()){
        return false;
    }

    if(X.length() and X[0] == S[0]){
        return isInterleaving(X.substr(1), Y, S.substr(1));
    }

    if (Y.length() and Y[0] == S[0]){
        return isInterleaving(X, Y.substr(1), S.substr(1));
    }
    return false;
}

    void main()
{
    string X = "ABC";
    string Y = "DEF";
    string S = "ADEBCF";

    if (isInterleaving(X, Y, S))
    {
        cout << "Interleaving";
    }
    else
    {
        cout << "Not an Interleaving";
    }
}