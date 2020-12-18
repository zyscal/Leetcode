#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct group
{
    int small_group[5];
};
bool bmp(group a, group b)
{
    return a.small_group[2] < b.small_group[2];
}
void add_list_yu(vector<int> &list, vector<int> &list_ans, int numofgroup, int yu)
{
    if(yu == 0)
    {
        return;
    }
    for(int i = 0; i < yu; i++)
    {
        list_ans.push_back(list[numofgroup * 5 + i]);
    }
    return;
}

int BFPRT(vector<int> list, int k)//第k小问题
{
    cout << "enter into bprt" << endl;
    int sumnum = list.size();
    cout << "sumnum : " << sumnum << endl; 
    if(sumnum <= 5)
    {
        sort(list.begin(), list.end());
        return list[k - 1];
    }
    int numofgroup = sumnum / 5;
    int yu = sumnum - numofgroup * 5;
    cout << "numofgroup : " <<numofgroup << "   yu : " << yu << endl;
    vector<group> group_list;
    for(int i = 0; i < numofgroup; i++)
    {
        group temgroup;
        for(int j = 0; j < 5; j++)
        {
            temgroup.small_group[j] = list[5 * i + j];
        }
        sort(temgroup.small_group,temgroup.small_group + 5);
        group_list.push_back(temgroup);
    }
    sort(group_list.begin(), group_list.end(), bmp);
    for(int i = 0; i < numofgroup; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << group_list[i].small_group[j] << " ";
        }
        cout << endl;
    }
    int midrow = numofgroup / 2;
    if(numofgroup % 2 == 0)
    {
        midrow -= 1;
    }
    cout << "midrow : " << midrow << endl;
    if((midrow + 1) * 3 >= k)
    {
        vector<int> nextlist;
        for(int i = 0; i <= midrow; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        add_list_yu(list, nextlist, numofgroup, yu);
        cout << "nextlist : ";
        for(int i = 0; i < nextlist.size(); i++)
        {
            cout << nextlist[i] << " ";
        }
        cout << endl;
        return BFPRT(nextlist, k);
    }
    else
    {
        vector<int> nextlist;
        for(int i = 0; i <= midrow; i++)
        {
            for(int j = 3; j < 5; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        for(int i = midrow + 1; i < numofgroup; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                nextlist.push_back(group_list[i].small_group[j]);
            }
        }
        add_list_yu(list, nextlist, numofgroup, yu);
        return BFPRT(nextlist, k - 3 * (midrow + 1));
    }
}

int main()
{
    vector<int> testans = {9,6,5,8,45,66,46,46,1,13,13,1,1,5,64,94,65,7,9,5,46,5,1,3,23,1,56,79,7,5,6,31,31,31,3,2,23,13,13,2,1,31,3};
    int ans = BFPRT(testans,5);
    cout << "ans : " << ans << endl;
    sort(testans.begin(), testans.end());
    for(int i = 0; i < testans.size(); i++)
    {
        cout << testans[i] << " ";
    }

}