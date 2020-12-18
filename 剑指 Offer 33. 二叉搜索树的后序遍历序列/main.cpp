#include<iostream>
#include<vector>
using namespace std;
bool verifyPostorder(vector<int>& postorder) {
    // for(int i = 0; i < postorder.size(); i++)
    // {
    //     cout<<postorder[i]<<" ";
    // }
    // cout<<endl;
    if(postorder.size() == 0 || postorder.size() == 1)
    {
        return true;
    }

    int root = postorder[postorder.size() - 1];
    int label = postorder.size() - 1;
    vector<int> right;
    vector<int> left;
    while(label - 1 >= 0 && postorder[label - 1] > root)
    {
        right.insert(right.begin(),postorder[label - 1]);
        label -= 1;
    }
    while (label - 1 >= 0 && postorder[label - 1] < root)
    {
        left.insert(left.begin(),postorder[label - 1]);
        label -= 1;
        /* code */
    }
    // cout<<"   label : "<<label<<endl;
    if(label != 0)
    {
        return false;
    }
    if(verifyPostorder(right) && verifyPostorder(left))
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> a = {1,2,5,10,6,9,4,3};
    cout<<verifyPostorder(a);
}