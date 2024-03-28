#include <bits/stdc++.h>
using namespace std;

bool wordBreak(vector<string> const &dict, string word, vector<int> &lookup)
{
    if (word.size() == 0)
    {
        return true;
    }
    if (lookup[word.size()] == -1)
    {
        lookup[word.size()] = 0;
        for (int i = 1; i <= word.size(); i++)
        {
            string prefix = word.substr(0, i);

            if (find(dict.begin(), dict.end(), prefix) != dict.end() and wordBreak(dict, word.substr(i), lookup))
            {
                return true;
            }
        }
    }
    return false;
}

void main(){
    vector<string> dict = {"this", "th", "is", "famous", "Word", "break",
                           "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"};

    // input string
    string word = "Wordbreakproblem";
    vector<int> lookup(word.length() + 1, -1);
    cout << wordBreak(dict, word, lookup);
}