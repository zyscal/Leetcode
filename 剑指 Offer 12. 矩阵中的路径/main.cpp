#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool findans(vector<vector<char>>&board , string word, vector<vector<bool>>& boolmap, int hang, int lie, int k)
{
    if(k == word.size())
        return true;
    for(int i = 0; i < 4; i++)
    {
        //首先四个方向不出格
        //没有被遍历过
        //存在word0
        if( hang + dx[i]>=0 && hang + dx[i] < board.size() && lie + dy[i] >= 0 && lie + dy[i] < board[0].size()
        && boolmap[hang + dx[i]][lie + dy[i]] && board[hang + dx[i]][lie + dy[i]] == word[k])
        {

            vector<vector<bool>> temboolmap(boolmap);
            temboolmap[hang + dx[i]][lie + dy[i]] = false;
            if(findans(board, word, temboolmap, hang + dx[i], lie + dy[i],k + 1))
                return true;
        }
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    if (word.size() == 0)
    {
        return true;
        /* code */
    }
    
    int hang = board.size();
    int lie = board[0].size();
    vector<vector<bool>> boolmap(hang);
    for(int i = 0; i < hang; i++)
    {
        boolmap[i].resize(lie,true);
    }
    for(int i = 0; i < hang; i++)
    {
        for(int j = 0; j < lie; j++)
        {
            if(board[i][j] == word[0])//第一个字母
            {
                vector<vector<bool>> temboolmap(boolmap);
                temboolmap[i][j] = false;
                if( findans(board, word, temboolmap, i, j, 1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{

    vector<vector<char>> board = { { 'A','B'}, {'C','D'} };
    string word = "ABCD";
    cout<<exist(board,word);
    return 0;
}