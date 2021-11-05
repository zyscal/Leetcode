#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n,m,q;
    cin >> n >> m>> q;
    vector<int> ans(n + 5);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ans.at(a)++;
        ans.at(b)++;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        swap(ans.at(a), ans.at(b));
    }
    for(int i = 1; i < n; i++){
        cout << ans.at(i) << " ";
    }
    cout << ans.at(n);
}