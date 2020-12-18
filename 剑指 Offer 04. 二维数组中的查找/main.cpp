#include<iostream>
#include<vector>
using namespace std;


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

    
       if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int temn = 0;
    int temm = matrix[0].size() - 1;
    while(true)
    {
        if(matrix[temn][temm] == target)
            return true;
        else if(matrix[temn][temm] > target)
        {
            temm--;
            if (temm == -1)
                break;
        }
        else
        {
            temn++;
            if(temn == matrix.size())
                break;
        }
    }
    return false;
}

int main()
{

}