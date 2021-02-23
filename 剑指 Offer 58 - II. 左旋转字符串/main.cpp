#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string last = "";
        for(int i = 0; i < n; i++)
        {
            last += s[i];
        }
        string before = "";
        for(int i = n; i < s.size(); i++)
        {
            before += s[i];
        }
        return before + last;
    }
};