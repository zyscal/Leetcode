#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> caozuolist;

void caozuo0 (string &s, string &t, vector<int> caozuo) {
    int l1 = caozuo.at(1);
    int r1 = caozuo.at(2);
    int l2 = caozuo.at(3);
    int r2 = caozuo.at(4);
    l1--;
    r1--;
    l2--;
    r2--;
    for(int i = 0; i < r1 - l1 + 1; i++){
        swap(s.at(l1 + i), t.at(l2 + i));
    }
}

void caozuo1 (string &s, string &t, int id, int x){
    x--;
    if(id == 0){
        if(s.at(x) == '1'){
            s.at(x) == '0';
        } else{
            s.at(x) == '1';
        }
    } else {
        if(t.at(x) == '1'){
            t.at(x) == '0';
        } else {
            t.at(x) == '1';
        }
    }
}
int func(string s, string t, int id, int pos, int n, int nList) {
    // cout << "-----------" << endl;
    // cout <<"id : " << id << endl;
    // cout << "n :" << n << endl;
    // cout <<"s : " << s << endl;
    // cout <<"t : " << t << endl;
        if(id == 0 && s.at(pos) == '1'){
            return n;
        }
        if(id == 1 && t.at(pos) == '1'){
            return n;
        }
        for(int i = nList; i < caozuolist.size(); i++){
            if(caozuolist.at(i).at(0) == 1 && id == caozuolist.at(i).at(1) && pos + 1 == caozuolist.at(i).at(2)){
                return n + 1;   
            }
        }
        for(int i = nList; i < caozuolist.size(); i++) {
            int ans;
            string ss = s;
            string tt = t;
            if(caozuolist.at(i).at(0) == 0){
                caozuo0(ss, tt, caozuolist.at(i));
                ans = func(ss, tt, id, pos, n + 1, i + 1);
            }
            else {
                caozuo1(ss, tt, caozuolist.at(i).at(1), caozuolist.at(i).at(2));
                ans = func(ss, tt, id ,pos, n + 1, i + 1);
            }
            if(ans != -1){
                    return ans;
                }
        }
        return -1;

}
int main(){
    string s;
    string t;
    int length;
    cin >> length;
    cin >> s;
    cin >> t;
    int caozuolength;
    cin >> caozuolength;
    for(int i = 0 ; i < caozuolength; i++){
        vector<int> temcaozuolist;
        int caozuoshu;
        cin >> caozuoshu;
        temcaozuolist.push_back(caozuoshu);
        if(caozuoshu == 1){
            int a;
             int b;
            cin >> a >> b;
            temcaozuolist.push_back(a);
            temcaozuolist.push_back(b);
        } else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            temcaozuolist.push_back(a);
            temcaozuolist.push_back(b);
            temcaozuolist.push_back(c);
            temcaozuolist.push_back(d);
        }
        caozuolist.push_back(temcaozuolist);
    }
    // for(int i = 0; i < caozuolist.size(); i++){
    //     for(int j = 0; j < caozuolist.at(i).size(); j++){
    //         cout << caozuolist.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < length; i++){
        cout << func(s, t, 0, i, 0, 0) << " ";
    }
    cout << endl;
    for(int i = 0; i < length; i++){
        cout << func(s, t, 1, i, 0, 0) << " ";
    }
}