#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int nowdx = 0;
int nowdy = 1;
int nowdir = 0;
void changedir()
{
    nowdir = (nowdir + 1) % 4;
    nowdx = dx[nowdir];
    nowdy = dy[nowdir];
    return;
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
    {
        vector<int> tem(0);
        return tem;
    }
    int height = matrix.size();
    int width = matrix[0].size();
    vector<int> ans;
    vector < vector<bool>> temmatrix(height);
    for(int i = 0; i < height; i++)
    {
        temmatrix[i].resize(width,true);
    }
    int nowx = 0;
    int nowy = 0;
    temmatrix[nowx][nowy] = false;
    ans.push_back(matrix[nowx][nowy]);
    for(int i = 1; i < height * width; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(nowx + nowdx >= 0 && nowx + nowdx < height
             && nowy + nowdy >= 0 && nowy + nowdy < width
             && temmatrix[nowx + nowdx][nowy + nowdy])
            {
                nowx += nowdx;
                nowy += nowdy;
                temmatrix[nowx][nowy] = false;
                ans.push_back(matrix[nowx][nowy]);
                break;
            }
            changedir();

        }
    }
    return ans;
}
int main()
{
    vector< vector<int>> test = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiralOrder(test);
    return 0;

}