#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mapS(60, 0);
        vector<int> mapT(60, 0);
        for(int i = 0; i < t.size(); i++) {
            insert(mapT, t.at(i));
        }
        int distance = t.size();
        int left = 0; 
        int right = -1;
        int ans = 999999999;
        while (right < s.size())
        {
            if(distance != 0) {
                right++;
                if(deleteA(mapT, t.at(right))) {
                    distance--;
                } else {
                    continue;
                }
            }
            ans = min(ans, right - left + 1);
            if()
        }
        
    }
    void insert(vector<int> &map, char a) {
        if (a >= 'a' && a <= 'z') {
            map.at(a - 'a')++
        } else if(a >= 'A' && a <= 'Z') {
            map.at(a - 'A' + 26)++;
        }
    }
    bool deleteA(vector<int> &map, char a) {
        int pos;
        if(a >= 'a' && a <= 'z') {
            pos = a - 'a';
        } else if(a >= 'A' && a <= 'Z') {
            pos = a - 'A' + 26;
        }
        if(map.at(pos) == 0) {
            return false;
        } else {
            map.at(pos)--;
            return true;
        }
    }
};