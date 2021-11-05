#include <iostream>
#include <string>
using namespace std;
void func(string a){
    bool check = true;// 判断结果是否正确；
    bool positive = true;// 是否正数；
    bool point = false;// 是否遍历到了小数点符号
    double ans = 0;
    double wei = 0.1;
    for(int i = 0; i < a.size(); i ++){
        if(a.at(i) == '-' && i == 0){
            positive = false;
        } else if( a.at(i) >= '0' && a.at(i) <= '9' && !point){
            ans *= 10;
            ans += a.at(i) - '0';
        } else if(a.at(i) >= '0' && a.at(i) <= '9' && point){
            ans = ans + (a.at(i) - '0') * wei;
            wei /= 10;
        } else if(a.at(i) == '.' && !point){
            point = true;
        } else {
            cout << "ret=false, result 不设置" << endl;
            return;
        }
    }
    if(!positive){
        ans *= -1;
    }
    cout << "ret=ture, result = "<< ans << endl;
}
