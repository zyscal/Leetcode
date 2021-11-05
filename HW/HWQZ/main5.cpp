// 给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
// 解答要求时间限制：1000ms, 内存限制：64MB

// 输入样例 1?
// abcabcbb
// 输出样例 1
// bca

// 输入样例 2?
// bbbbb    
// 输出样例 2
// b

// 输入样例 3?
// pwwkew
// 输出样例 3
// wke
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string a;
    cin >> a;
    int length = a.size();
    vector<vector<bool>> StringMap(length); // 动规
    for(int i = 0; i < length; i++){
        StringMap.at(i).resize(length, false);
    }
    for(int i = 0; i < length; i++){
        StringMap.at(i).at(i) = true; // 长度为1的字符串为真
    }
    for(int i = 0; i < length; i++){ // 上三角,每一个起点
        for(int j = i + 1; j < length; j++){ // 到终点
            if(StringMap.at(i).at(j - 1) == false){
                StringMap.at(i).at(j) = false;
            } else {
                bool check = true;
                for(int k = i; k < j; k++){
                    if(a.at(k) == a.at(j)){
                        check = false;
                        break;
                    }
                }
                StringMap.at(i).at(j) = check;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < length; i++){
        for(int j = i; j < length; j++){
            if (StringMap.at(i).at(j))
            {
                ans = max(ans, j - i + 1);
                /* code */
            }
            
        }
    }
    cout << ans << endl;
}