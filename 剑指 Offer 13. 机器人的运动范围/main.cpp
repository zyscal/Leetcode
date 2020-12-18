#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool countsum(int a, int b, int k)
{
    int suma = 0;
    while (a/10 != 0)
    {
        suma += a%10;
        a /= 10;
    }
    suma += a;

    int sumb = 0;
    while (b/10 != 0)
    {
        sumb += b%10;
        b /= 10;
    }
    sumb += b;
    return suma + sumb - k <= 0 ? true : false;
}
int countans(vector<vector<bool>> &boolmap, vector<vector<bool>> &haswalk, int hang, int lie)
{
    int tem = 0;
    for(int i = 0; i < 4; i++)//四个方向，不能出格,可以走,没有走过
    {
        if(hang + dx[i] >= 0 && hang + dx[i] < boolmap.size() && lie + dy[i] >= 0 && lie + dy[i] < boolmap[0].size() 
        && boolmap[hang + dx[i]][lie + dy[i]] == true && haswalk[hang + dx[i]][lie + dy[i]] == false)
        {
            haswalk[hang + dx[i]][lie + dy[i]] = true;
            tem += countans(boolmap, haswalk, hang + dx[i], lie + dy[i]) + 1;
        }
    }
    return tem;
}

int movingCount(int m, int n, int k) {
    vector< vector<bool>> boolmap(m);
    for(int i = 0; i < m; i++)
    {
        boolmap[i].resize(n, true);
    }
    vector<vector<bool>> haswalk(m);
    for(int i = 0; i < m; i++)
    {
        haswalk[i].resize(n, false);
    }
    haswalk[0][0] = true;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            boolmap[i][j] = countsum(i, j, k);
        }
    }
    return countans(boolmap, haswalk, 0, 0) + 1;
}
int main()
{
    cout<<movingCount( 3,1,0);
    return 0;
}