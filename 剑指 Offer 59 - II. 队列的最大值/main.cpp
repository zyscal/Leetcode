#include<vector>
#include<queue>
#include<iostream>
using namespace std;

// int main()
// {
//     vector<int> a;
//     for(int i = 0; i < 20; i++)
//     {
//         a.push_back(i);
//     }
//     a.erase(a.begin() + 10);
//     for(int i = 0; i < a.size(); i++)
//     {
//         cout << a[i] << " ";
//     }
// }

class MaxQueue {
public:
    queue<int> list;
    vector<int> anslist;


    MaxQueue() {
        while( !list.empty())
        {
            list.pop();
        }
        anslist.clear();
    }
    
    int max_value() {
        if(anslist.size() == 0)
        {
            return -1;
        }
        return anslist[0];
    }
    
    void push_back(int value) {
        list.push(value);
        for(int i = 0; i < anslist.size(); i++)
        {
            if(anslist[i] < value)
            {
                anslist.erase(anslist.begin() + i, anslist.end());
                break;
            }
        }
        anslist.push_back(value);
        return;
    }
    
    int pop_front() {
        if(list.empty())
        {
            return -1;
        }
        int front = list.front();
        list.pop();
        if(front == anslist[0])
        {
            anslist.erase(anslist.begin());
        }
        return front;
    }
};
