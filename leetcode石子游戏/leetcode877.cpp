#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sumpiles(vector<int> &piles, int i, int j)
{
    int sum = 0;
    for(int tem = i; tem <= j; tem++)
    {
        sum += piles[tem];
    }
    return sum;
}

bool stoneGame(vector<int>& piles) 
{
    int LEN = piles.size();
    vector< vector<int> > ansdp(LEN);//ansdp存储的内容是：对于0-LEN - 1的数列，从i到j部分内容，先拿的人可以最多拿到多少分
    for(int i = 0; i < LEN; i++)
    {
        ansdp[i].resize(LEN, 0);
    }
    for(int i = 0; i < LEN; i++)
    {
        for(int j = 0; j + i < LEN; j++)
        {
            if (i == 0)
            {
                ansdp[j][j] = piles[j];
                /* code */
            }
            else
            {
                int left = j;
                int right = j + i;
                int findleft = piles[left] + sumpiles(piles, left + 1, right) - ansdp[left + 1][right];
                int findright = piles[right] + sumpiles(piles, left, right - 1) - ansdp[left][right - 1];
                ansdp[left][right] = max(findleft,findright);
            }
        }
    }

    for(int i = 0; i < LEN; i++)
    {
        for(int j = 0; j < LEN; j++)
        {
            cout<<ansdp[i][j]<<" ";
        }
        cout<<endl;
    }
    int sumofpiles = sumpiles(piles, 0, LEN - 1);
    if (ansdp[0][LEN - 1] > sumofpiles - ansdp[0][LEN - 1])
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    vector<int> test = {5,3,4,5};
    cout<<stoneGame(test);


    return 0;
}