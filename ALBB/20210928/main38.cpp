#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> ans;
void func(vector<vector<char>> &nineMap, string &a, int pos, vector<char> temans){
    if(pos == a.size()){
        ans.push_back(temans);
        return;
    }
    int getID = a.at(pos) - '0';
    for(int i = 0; i < nineMap.at(getID).size(); i++){
        vector<char> onePath = temans;
        onePath.push_back(nineMap.at(getID).at(i));
        func(nineMap, a, pos + 1, onePath);
    }
    return ;
}
int main(){
    vector<vector<char>> nineMap = {{'0'},{'1'}, {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
    {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<char> temans;
        string a ="78";
    func(nineMap, a, 0, temans);
    for(int i = 0 ; i < ans.size(); i++){
        for(int j = 0; j < ans.at(i).size(); j++){
            cout << ans.at(i).at(j);
        }
        cout << endl;
    }
}