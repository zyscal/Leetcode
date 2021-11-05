#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int num, k;
        cin >> num >> k;
        vector<int> list;
        while(num >= k){
            list.push_back(num % k);
            num = num / k;
        }
        list.push_back(num);
        int ans = 0;
        int tem = 1;
        for(int i = list.size() - 1; i >= 0; i--){
            ans += list.at(i) * tem;
            tem *= k;
        }
        cout << ans << endl;
    }
}