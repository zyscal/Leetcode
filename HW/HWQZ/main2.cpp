#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool cmp(string a, string b) {
    return a < b;
}
struct node
{
    string nodeName;
    vector<bool> instance;// 1 为实例，0为子概念
    vector<node> nodeList; // 下一节点地址
};
void dfs(vector<string> &ans, unordered_map<string, node> node_map, string root){
    node rootNode = node_map.find(root)->second;
    for(int i = 0; i < rootNode.instance.size(); i++) {
        if(rootNode.instance.at(i)) {
            ans.push_back(rootNode.nodeList.at(i).nodeName);
        }else {
            dfs(ans, node_map, rootNode.nodeList.at(i).nodeName);
        }
    }
}
unordered_map<string, node> node_map;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a,b,c;
        cin >> a >> b >> c;
        bool instance;
        if(b.at(0) == 's') { // 子概念
            instance = false;
        }else if(b.at(0) == 'i'){ // 实例
            instance = true;
        }
        //  父概念
        node parentNode;
        parentNode.nodeName = c;
        node childNode;
        childNode.nodeName = a;
        // 先看父概念有没有
        auto iter = node_map.find(parentNode.nodeName);
        if(iter != node_map.end()) { // 有

        } else {

            node_map.insert(pair<string, node>(parentNode.nodeName, parentNode));
        }
        // 将子概念添加图中
        
        auto iterp = node_map.find(parentNode.nodeName);
        iterp->second.instance.push_back(instance);
        iterp->second.nodeList.push_back(childNode);
        node_map.insert(pair<string, node>(parentNode.nodeName, parentNode));
        node_map.insert(pair<string, node>(childNode.nodeName, childNode));

    auto iter1 = node_map.begin();

    while(iter1 != node_map.end()) {

        iter1++;
    }

    }

    string ansNode;
    cin >> ansNode;
    vector<string> ans;
    auto iter2 = node_map.find(ansNode);
    node zys = node_map.find(ansNode)->second;


    dfs(ans, node_map, ansNode);
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.at(0);
    for(int i = 1; i < ans.size(); i++) {
        cout<< " " << ans.at(i);
    }
    return 0;
}




