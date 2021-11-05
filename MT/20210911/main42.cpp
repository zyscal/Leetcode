#include<iostream>
#include<vector>
using namespace std;
void findzhouqi(vector< vector<int>> list, vector< vector<int>> zhouqi, int length) {
    for(int i = 0; i < 26; i++){
        for(int j = 1; j < list.at(i).size(); j++){
            int zhouqibeixuan = list.at(i).at(j);
            int pos = 0;
            int k = 0;
            while(pos < length){
                if()
            }
        }

    }
}
int main() {
    vector< vector<int>> ans_list(30);
    string list;
    cin >> list;
    int num;
    cin >> num;
    for(int i = 0; i < list.size(); i++){
        ans_list.at(list.at(i) - 'a').push_back(i);
    }
    for(int i = 0; i < num; i++){
        int n,k;
        cin >> n >> k;
        vector< vector<int>> zhouqi(30);


    }


}