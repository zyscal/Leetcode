#include<vector>
#include<stack>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if(pushed.size() == 0)
    {
        return true;
    }
    int tempushed = 0;
    int tempopped = 0;
    stack<int> thisstack;
    while(tempopped < popped.size())
    {
        if(thisstack.empty())
        {
            if(tempushed < pushed.size())
            {
                thisstack.push(pushed[tempushed]);
                tempushed++;
            }
            else
            {
                return false;
            }
        }
        if(thisstack.top() == popped[tempopped])
        {
            tempopped++;
            thisstack.pop();
            continue;
        }
        if(tempushed < pushed.size())
            {
                thisstack.push(pushed[tempushed]);
                tempushed++;
            }
            else
            {
                return false;
            }
    }
    return true;
}