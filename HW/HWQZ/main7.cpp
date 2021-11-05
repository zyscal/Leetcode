#include <iostream>
#include <string>
using namespace std;
// s = "3[a]2[bc]", 返回 "aaabcbc".
// s = "3[a2[c]df3[r[yy]]]", 返回 "accaccacc".
// s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".


// string decodeString(string s){

// }
string func(string &s, int beginPos, int endPos){
    string ans = "";
    int left = 0;
    int times = 0;
    bool checkleft = false;
    int nextleft = beginPos;
    int nextright = beginPos;
    for(int i = beginPos; i <= endPos; i++){
        if(checkleft == false){ // 还没有左边
            if(s.at(i) >= 'a' && s.at(i) <= 'z'){
                ans += s.at(i);
            }
            else
            {
                times *= 10;
                times += s.at(i) - '0';
            }
        }
        if(s.at(i) == '[' && checkleft == false){
            nextleft = i + 1;
            checkleft = true;
            left ++;=
        } else if(s.at(i) == ']' && checkleft == true){
            left --;
        }
        if(checkleft && left == 0){
            nextright = i - 1;
            string nextdepth = func(s, nextleft, nextright);
            for(int j = 0; j < times; j++){
                ans += nextdepth;
            }
            checkleft = false;
            left = 0;
            times = 0;
        }
    }
    return ans;





    }
    for(int i = beginPos; i < s.size(); i++){

    }

}
int main(){
    string a = "1";
    string b = "2";
    string c = a + b;
    cout << c << endl;
}