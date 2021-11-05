#include<iostream>
#include <vector>
using namespace std;

int func(int a){
    int ans = 0;
    while(a / 10 != 0) {
        ans *= 10;
        ans += a % 10;
        a /= 10;
    }
    ans *= 10;
    ans += a;
    return ans;
}
int main() {
    int N, K;
    cin >> N >> K;
    int max_ans = -9999999;
    vector<int> list;
    vector<int> change;
    for(int i = 1; i <= K; i++){
        int tem_max = func(i * N);
        if(tem_max > max_ans) {
            max_ans = tem_max;
        }
    }
    cout << max_ans;
}
