#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n.size() - 1; i++){
        long long ji = n.at(i) - '0';
        long long ou = 0;
        for(int j = i + 1; j < n.size(); j++){
            if((j - i) % 2 == 1) {
                ou += n.at(j) - '0';
            } else {
                ji += n.at(j) - '0';
            }
            if((n.at(j) - '0') % 2 == 0){ // 是个偶数
                if((ji - ou) % 11 == 0){
                    ans += 1;
                }
            }
        }
    }
    cout << ans;
}


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// vector<int> chu2(vector<char> a){
//     int yu = 0;
//     vector<int> ans;
//     for(int i = 0; i < a.size(); i++){
//         yu = yu * 10;
//         yu += a.at(i) - '0';
//         ans.push_back(yu / 2);
//         yu = yu % 2;
//     }
//     int i = 0;
//     for(; i < ans.size(); i++){
//         if(ans.at(i) != 0){
//             break;
//         }
//     }
//     vector<int> list;
//     for(;i < ans.size(); i++){
//         list.push_back(ans.at(i));
//     }
//     return list;
// }

// int main(){
//     string n;
//     cin >> n;
//     int ans = 0;
//     for(int i = 0; i < n.size() - 1; i++){
//         vector<int> list;
//         list.push_back(n.at(i) - '0');
//         for(int j = i + 1; j < n.size(); j++){
//             list.push_back(n.at(j) - '0');
//             if((n.at(j) - '0') % 2 == 0){ // 是个偶数
//                 int ji = 0;
//                 int ou = 0;
//                 for(int k = 0; k < list.size(); k++){
//                     if(k %2 == 0){
//                         ji += list.at(k);
//                     }
//                     else{
//                         ou += list.at(k);
//                     }
//                 }
//                 if((ji - ou) % 11 == 0){
//                     ans += 1;
//                 }
//             }
//         }
//     }
//     cout << ans;
// }
