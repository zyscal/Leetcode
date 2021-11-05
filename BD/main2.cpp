#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<pair<int, int>, bool> ans_map;

bool func(string &list, int begin, int end){
    if(list.at(begin) == list.at(end)){
        cout << begin + 1 << " " << end << " " << begin + 2 << " " << end + 1;
        return true;
    }
    if(ans_map.find(make_pair(begin + 1, end)) == ans_map.end()){
        if(func(list, begin + 1, end)){
            return true;
        }
        else{
            ans_map.insert(make_pair(make_pair(begin + 1, end), false));
        }
    }
    if(ans_map.find(make_pair(begin, end - 1)) == ans_map.end()){
        if(func(list, begin, end - 1)){
            return true;
        }
        else{
            ans_map.insert(make_pair(make_pair(begin, end - 1), false));
        }
    }

    return false;
}
int main() {
    string list;
    cin >> list;
    func(list, 0, list.size() - 1);
    return 0;


}

