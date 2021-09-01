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
    vector<node*> nodeList; // 下一节点地址
};
unordered_map<string, node*> node_map;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a,c;
        cin >> a >> c;
        //  父概念
        // node *parentNode = new node;
        node *parentNode = (node *)malloc(sizeof(node));
        parentNode->nodeName = c;
        // node *childNode = new node;
        node *childNode = (node *)malloc(sizeof(node));
        childNode->nod3eName = a;
        // 先看父概念有没有
        auto iter = node_map.find(parentNode->nodeName);
        if(iter != node_map.end()) { // 有

        } else {
            node_map.insert(pair<string, node*>(parentNode->nodeName, parentNode));
        }
        node_map.insert(pair<string, node*>(childNode->nodeName, childNode));
        auto iter1 = node_map.begin();
        cout << "---------" << endl;
        while(iter1 != node_map.end()) {
            cout << iter1->second->nodeName << endl;
            iter1++;
        }
        cout << "---------" << endl;
    }
    return 0;
}
