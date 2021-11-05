#include <iostream>
#include <vector>
using namespace std;
/**
 * list 描述了所有的数组中数字
 * listPos描述了当前遍历到那个位置
 * path描述了当前的路径， 其中false为左边，true为右边
 * status中左边int描述了上一个节点A中总和，右边int描述了B中总和。
 */
int min_sum = 99999999;
vector<bool> ansPath;
int getdif(int a, int b){
    if (a > b){
        return a - b;
    }
    return b - a;
}
void func(vector<int> &list, int listPos, vector<bool> path, pair<int, int> status){
    if(listPos == list.size()){
        int dif = getdif(status.first, status.second);
        if(dif < min_sum){
            ansPath = path;
            min_sum = dif;
        }
        return;
    }
    int newListPos = listPos + 1;
    vector<bool> pathLeft = path;
    vector<bool> pathright = path;
    pathLeft.push_back(false);
    pathright.push_back(true);
    func(list, newListPos, pathLeft, make_pair(status.first + list.at(listPos), status.second));
    func(list, newListPos, pathright, make_pair(status.first, status.second + list.at(listPos)));
    return ;
}

int main() {
    vector<int> list = {10,9,6,5,4,3,3};
    vector<bool> path;
    vector<int> A;
    vector<int> B;
    func(list, 0, path, make_pair(0, 0));
    for(int i = 0; i < ansPath.size(); i++){
        if(ansPath.at(i)){
            B.push_back(list.at(i));
        } else
        {
            A.push_back(list.at(i));
        }
    }
    cout << "A : ";
    for(int i = 0 ; i < A.size(); i++){
        cout << A.at(i) << " ";
    }
    cout << endl;
    cout << "B : ";
    for(int i = 0 ; i < B.size(); i++) {
        cout << B.at(i) << " ";
    }
    cout << endl;
}